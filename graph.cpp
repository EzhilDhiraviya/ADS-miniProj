#include<iostream>
#include<bits/stdc++.h>
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
class Graph
{
    int no_of_vertices;
    struct vertex
    {
        int vertex_no;
    };
    struct edge
    {
        int weight;
        struct vertex *from;
        struct vertex *to;
    };

    vector<vertex> vertices;
    vector<edge> edges;

    public:

    Graph(int n)
    {
        no_of_vertices = n;
        vertices.resize(n);
        for(int i=0;i<n;i++)
        {
            vertices[i].vertex_no = i;
        }
        mapping("mapping.txt");
    }

    void addEdge(int from, int to, int weight)
    {
        edge e;
        e.weight = weight;
        e.from = &vertices[from];
        e.to = &vertices[to];
        edges.push_back(e);
        e.from = &vertices[to];
        e.to = &vertices[from];
        edges.push_back(e);
    }

    void displayAdjacencyList()
    {
        vector<vector<int>> adjacencyList(no_of_vertices);
        for(int i=0;i<edges.size();i++)
        {
            adjacencyList[edges[i].from->vertex_no].push_back(edges[i].to->vertex_no);
        }
        for(int i=0;i<no_of_vertices;i++)
        {
            cout<<Map[i]<<" -> ";
            for(int j=0;j<adjacencyList[i].size();j++)
            {
                cout<<Map[adjacencyList[i][j]]<<" ";
            }
            cout<<endl;
        }
    }
    
};




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