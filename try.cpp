#include <iostream>
#include <fstream>
#include <string>
#include "avl.h"
#include <unordered_map>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Define a structure to represent a node in the graph
struct GraphNode {
    int id;
    string label;
    vector<int> neighbors; // IDs of neighboring nodes
};

unordered_map<int, GraphNode> Graph; // Map to store graph nodes by their IDs

// Function to load mapping and syllabus data from files
void loadData() {
    // Load mapping data
    ifstream fileformap("navigation.txt");
    int nodeId;
    string label;
    while (fileformap >> nodeId >> label) {
        GraphNode node;
        node.id = nodeId;
        node.label = label;
        Graph[nodeId] = node;
    }

    // Define connections between nodes (graph edges)
    // Here, we manually define the connections for simplicity, but you can load them from a file or use a different approach
    // For example, you can have a file specifying the connections between nodes.

    // Define connections for Navigation
    Graph[1].neighbors = {2}; // 1: Navigation -> 2: Back
    Graph[2].neighbors = {1, 3}; // 2: Back -> 1: Navigation, 3: Home
    Graph[3].neighbors = {2}; // 3: Home -> 2: Back

    // Define connections for Syllabus
    Graph[4].neighbors = {5}; // 4: Syllabus -> 5: Enter Course ID
    Graph[5].neighbors = {4}; // 5: Enter Course ID -> 4: Syllabus
}

// Function to print the options available at the current node
void printOptions(int nodeId) {
    cout << "Options available:\n";
    for (int neighborId : Graph[nodeId].neighbors) {
        cout << Graph[neighborId].label << endl;
    }
}

// Function to handle navigation
void handleNavigation() {
    cout << "\nNavigation selected\n";
    printOptions(1); // Print options available at Node 1 (Navigation)
}

// Function to handle syllabus
void handleSyllabus() {
    cout << "\nSyllabus selected\n";
    printOptions(4); // Print options available at Node 4 (Syllabus)
}

// Function to go to the selected node
void goToNode(int nodeId) {
    switch (nodeId) {
        case 1: handleNavigation(); break;
        case 2: cout << "\nGoing back...\n"; break; // Implement going back logic
        case 3: cout << "\nGoing home...\n"; break; // Implement going home logic
        case 4: handleSyllabus(); break;
        case 5: // Implement enter course ID logic
                cout << "Enter the course ID: ";
                // Implement logic to handle entering course ID
                break;
        default: cout << "Invalid option!\n"; break;
    }
}

// Function to load syllabus data from file
void loadSyllabusData(map<string, string> &SyllabusMap) {
    ifstream fileforSyllabus("syllabus.txt");
    string id, syll;
    while (fileforSyllabus >> id >> syll) {
        SyllabusMap[id] = syll;
    }
}

// Function to search and display syllabus
void searchSyllabus(AvlTree<string> &avlTree, map<string, string> &SyllabusMap) {
    string courseId;
    cout << "Enter the course ID: ";
    cin >> courseId;

    // Search for the course ID in the AVL tree
    if (avlTree.contains(courseId)) {
        cout << "Syllabus for Course ID " << courseId << ": " << SyllabusMap[courseId] << "\n";
    } else {
        cout << "Course ID not found\n";
    }
}

int main() {
    loadData();
    
    // Load syllabus data into SyllabusMap
    map<string, string> SyllabusMap;
    loadSyllabusData(SyllabusMap);

    AvlTree<string> avlTree;

    int currentNode = 1; // Start at Node 1 (Navigation)
    int choice;
    do {
        cout << "\nWelcome to University Chatbot\n";

        // Print options available at the current node
        printOptions(currentNode);

        // Get user choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Check if the selected option is valid
        if (find(Graph[currentNode].neighbors.begin(), Graph[currentNode].neighbors.end(), choice) != Graph[currentNode].neighbors.end()) {
            // Go to the selected node
            goToNode(choice);
            currentNode = choice; // Update current node
        } else {
            cout << "Invalid option! Please enter a valid option.\n";
        }
    } while (currentNode != 3); // Exit loop when reaching Node 3 (Home)

    return 0;
}
