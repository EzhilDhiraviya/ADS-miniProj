#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
            cout<<i<<" -> ";
            for(int j=0;j<adjacencyList[i].size();j++)
            {
                cout<<adjacencyList[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
};

int main()
{
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,4,1);
    g.displayAdjacencyList();
    return 0;
}