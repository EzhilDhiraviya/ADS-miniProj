#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "avl.h"
#include "graph.h"

using namespace std;

// map<int, string> Map;
map<string, string> SyllabusMap;
Graph g(17);  // Assuming your graph has 17 vertices

// Function to load mapping and syllabus data from files
void loadData() {
    ifstream fileformap("mapping.txt");
    ifstream fileforSyllabus("syllabus.txt");
    int i;
    string s;

    // Load mapping data
    while (fileformap >> i >> s) {
        Map[i] = s;
    }

    // Load syllabus data
    string id, syll;
    while (fileforSyllabus >> id >> syll) {
        SyllabusMap[id] = syll;
    }
}

// Function to print the mapping data
void printMap() {
    for (int i = 0; i < 17; i++) {
        cout << i + 1 << "-->" << Map[i] << "\n";
    }
}

// Function to print the syllabus data
void printSyllabus() {
    for (auto i : SyllabusMap) {
        cout << i.first << ": " << i.second << "\n";
    }
}

// Function to handle syllabus search and display
void searchSyllabus(AvlTree<string> &avlTree) {
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

// Function to create the graph from edges file
void createGraph() {
    int u, v;
    ifstream file("edges.txt");
    while (file >> u >> v) {
        g.addEdge(u, v, 1); // Assuming all edges have weight 1
    }
}

int main() {
    loadData();
    AvlTree<string> avlTree;
    createGraph();

    int source, destination;
    int choice;
    do {
        cout << "\nWelcome to University Chatbot\n";
        cout << "1. Navigation\n";
        cout << "2. Syllabus\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nNavigation selected\n";
                g.dijkstra(15); // Assuming 15 is the source node
                g.displayShortestPath(6); // Assuming 6 is the destination node
                cout << endl;
                break;
            case 2:
                cout << "\nSyllabus selected\n";
                // Store syllabus data in AVL tree
                for (auto i : SyllabusMap) {
                    avlTree.insert(i.first);
                }
                // Search and display syllabus
                searchSyllabus(avlTree);
                break;
            case 3:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 3);

    return 0;
}
