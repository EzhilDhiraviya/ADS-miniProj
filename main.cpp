#include <bits/stdc++.h>
using namespace std;
#include "avl.h"

map<int,string> Map;
map<string,string>SyllabusMap;

void mapping(){

    ifstream fileformap("mapping.txt");
    ifstream fileforSyllabus("syllabus.txt");
    int i;
    string s;
    while(fileformap>>i>>s){
        Map[i] = s;
    }
    string id,syll;
    while(fileforSyllabus>>id>>syll){
        SyllabusMap[id] = syll;
    }
}

void printMap(){
    for(int i=0;i<17;i++){
        cout<<i+1<<"-->"<<Map[i]<<"\n";
    }
}

void printSyllabus(){
    for(auto i: SyllabusMap){
        cout<<i.first<<": "<<i.second<<"\n";
    }
}

void storeSyllabus(AvlTree<string>t){

    for(auto i: SyllabusMap){
        t.insert(i.first);
    }

    t.printTreeStructure();
}


int main(){
    AvlTree<string>t;

    mapping();
    printSyllabus();
    storeSyllabus(t);
    return 0;
}