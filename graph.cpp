#include <bits/stdc++.h>
#include "graph.h"
using namespace std;
int main()
{
    Graph g(17);
    int u,v;
    ifstream file("edges.txt");
    while(file>>u>>v){
        g.addEdge(u,v,1);
    }
    
    g.dijkstra(15);
    g.exportShortestPath(6, "shortest_path.txt", "shortest_path_edges.txt");

    // Call the Python script to display the shortest path
    system("python d.py");
    cout<<endl;
    return 0;
}