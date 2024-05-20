#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <sstream>
#include "avl.h"
#include "splay.h"

using namespace std;

unordered_map<int, pair<string, string>> question_answer;
AvlTree<int> t; 

void map_questions(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error opening file: " << file_name << endl;
        return;
    }

    string line;
    int id = 0;

    while (getline(file, line)) {
        t.insert(id);
        string question = line;
        if (getline(file, line)) {
            string answer = line;
            question_answer[id] = make_pair(question, answer);
            ++id;
        }
        
    }
}

void print_questions() {
    for (const auto& entry : question_answer) {
        cout << "Question ID " << entry.first << ": " << entry.second.first << "\nAnswer: " << entry.second.second << endl;
    }
}

int main() {
    map_questions("questions.txt");
    print_questions();
    t.printTreeStructure();

    
    return 0;
}
