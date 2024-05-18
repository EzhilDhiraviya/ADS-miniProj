#include <bits/stdc++.h>
#include "graph.h"
using namespace std;
int main()
{
    Graph g(17);
    int u,v;
    ifstream file("edges.txt");
    while(file>>u>>v){
        g.addEdge(u,v,0);
    }
    
    g.displayAdjacencyList();
    return 0;
}