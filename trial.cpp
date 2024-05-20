#include <iostream>
#include <bits/stdc++.h>
#include<cstdlib>
using namespace std;
int main() {
 

    
    int choice;
    do {
        cout << "\nWelcome to University Chatbot\n";
        cin>>choice;
    switch (choice) {
            case 1:
                cout << "\nNavigation selected\n";
               
                break;
            case 2:
                system("python disp.py");
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
