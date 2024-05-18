#include <bits/stdc++.h>
using namespace std;

map<int,string> Map;

void mapping(){

    ifstream file("mapping.txt");
    int i;
    string s;
    while(file>>i>>s){
        Map[i] = s;
    }
    for(int i=0;i<Map.size();i++){
        cout<<i+1<<"-->"<<Map[i]<<endl;
    }
}



int main(){
    mapping();

    return 0;
}