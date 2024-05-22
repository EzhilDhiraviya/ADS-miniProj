#include <iostream>
#include <fstream>
#include <vector>
#include<sstream>
#include "splay.h"
using namespace std;

void readQuestionsAndAnswers(const string& questionsFile, vector<string>& answers, SplayTree<string>& answerTree) {
    ifstream inFile(questionsFile);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file " << questionsFile << endl;
        return;
    }

    string question, answer;
    int index = 0;
    string ind;
    while (getline(inFile, ind)) {
        getline(inFile, question);
        getline(inFile, answer); // Read the corresponding answer
        answerTree.insert(question,answer); // Map question to its index
        answers.push_back(answer);
        index++;
    }

    inFile.close();
}

int main() {
    vector<string> answers;
    SplayTree<string> answerTree;

    string questionsFile = "questions.txt";
    string searchQuestion;
    readQuestionsAndAnswers(questionsFile, answers, answerTree);

    cout << "Enter the question you want to search: ";
    getline(cin, searchQuestion);

   answerTree.contains(searchQuestion);
        cout<<  "Question :" << answerTree.getTop().first << endl;
        cout << "Answer: " << answerTree.getTop().second << endl;

    //answerTree.printTree();
    return 0;
}
