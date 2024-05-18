#include <bits/stdc++.h>
using namespace std;

map<int,string> Map;

void mapping(string file_name){

    ifstream file(file_name);
    int i;
    string s;
    while(file>>i>>s){
        Map[i] = s;
    }
    
}



int main(){
    mapping("mapping.txt");

    return 0;
}