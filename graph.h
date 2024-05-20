// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// extern map<int,string> Map;
// void mapping(string file_name)
// {

//     ifstream file(file_name);
//     int i;
//     string s;
//     while(file>>i>>s){
//         Map[i] = s;
//     }
    
// }
// class Graph
// {
//     int no_of_vertices;
//     struct vertex
//     {
//         int vertex_no;
//         bool visited;
//         int path;
//         int distance;
//     };
//     struct edge
//     {
//         int weight;
//         struct vertex *from;
//         struct vertex *to;
//     };

//     vector<vertex> vertices;
//     vector<edge> edges;

//     public:

//     Graph(int n)
//     {
//         no_of_vertices = n;
//         vertices.resize(n);
//         mapping("mapping.txt");
//         for(int i=0;i<n;i++)
//         {
//             vertices[i].vertex_no = i;
//             vertices[i].visited = false;
//             vertices[i].path = -1;
//             vertices[i].distance = INT_MAX;
//         }
//     }

//     void resetVisited()
//     {
//         for(int i=0;i<no_of_vertices;i++)
//         {
//             vertices[i].visited = false;
//         }
//     }

//     void addEdge(int from, int to, int weight)
//     {
//         edge e;
//         e.weight = weight;
//         e.from = &vertices[from];
//         e.to = &vertices[to];
//         edges.push_back(e);
//         e.from = &vertices[to];
//         e.to = &vertices[from];
//         edges.push_back(e);
//     }

//     void displayAdjacencyList()
//     {
//         vector<vector<int>> adjacencyList(no_of_vertices);
//         for(int i=0;i<edges.size();i++)
//         {
//             adjacencyList[edges[i].from->vertex_no].push_back(edges[i].to->vertex_no);
//         }
//         for(int i=0;i<no_of_vertices;i++)
//         {
//             cout<<Map[i]<<" -> ";
//             for(int j=0;j<adjacencyList[i].size();j++)
//             {
//                 cout<<Map[adjacencyList[i][j]]<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     void dijkstra(int source)
//     {
//         resetVisited();
//         vertices[source].distance = 0;
//         vertices[source].path = -1;
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         pq.push({0,source});
//         while(!pq.empty())
//         {
//             int u = pq.top().second;
//             pq.pop();
//             if(vertices[u].visited)
//             {
//                 continue;
//             }
//             vertices[u].visited = true;
//             for(int i=0;i<edges.size();i++)
//             {
//                 if(edges[i].from->vertex_no == u)
//                 {
//                     int v = edges[i].to->vertex_no;
//                     if(vertices[v].distance > vertices[u].distance + edges[i].weight)
//                     {
//                         vertices[v].distance = vertices[u].distance + edges[i].weight;
//                         vertices[v].path = u;
//                         pq.push({vertices[v].distance,v});
//                     }
//                 }
//             }
//         }
//     }

//     void displayShortestPath(int destination)
//     {
//         if(vertices[destination].distance == INT_MAX)
//         {
//             cout<<"No path exists"<<endl;
//             return;
//         }
//         if(vertices[destination].path != -1)
//             displayShortestPath(vertices[destination].path);
//         cout<<Map[destination]<<" ";
//         cout<<"---->  ";
//     }

// };


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

extern map<int, string> Map;

class Graph
{
    int no_of_vertices;
    struct vertex
    {
        int vertex_no;
        bool visited;
        int path;
        int distance;
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
        for (int i = 0; i < n; i++)
        {
            vertices[i].vertex_no = i;
            vertices[i].visited = false;
            vertices[i].path = -1;
            vertices[i].distance = INT_MAX;
        }
        mapping("mapping.txt");  // Call the mapping function here
    }

    void resetVisited()
    {
        for (int i = 0; i < no_of_vertices; i++)
        {
            vertices[i].visited = false;
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
        for (int i = 0; i < edges.size(); i++)
        {
            adjacencyList[edges[i].from->vertex_no].push_back(edges[i].to->vertex_no);
        }
        for (int i = 0; i < no_of_vertices; i++)
        {
            cout << Map[i] << " -> ";
            for (int j = 0; j < adjacencyList[i].size(); j++)
            {
                cout << Map[adjacencyList[i][j]] << " ";
            }
            cout << endl;
        }
    }

    void dijkstra(int source)
    {
        resetVisited();
        vertices[source].distance = 0;
        vertices[source].path = -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if (vertices[u].visited)
            {
                continue;
            }
            vertices[u].visited = true;
            for (int i = 0; i < edges.size(); i++)
            {
                if (edges[i].from->vertex_no == u)
                {
                    int v = edges[i].to->vertex_no;
                    if (vertices[v].distance > vertices[u].distance + edges[i].weight)
                    {
                        vertices[v].distance = vertices[u].distance + edges[i].weight;
                        vertices[v].path = u;
                        pq.push({vertices[v].distance, v});
                    }
                }
            }
        }
    }

    void displayShortestPath(int destination)
    {
        if (vertices[destination].distance == INT_MAX)
        {
            cout << "No path exists" << endl;
            return;
        }
        if (vertices[destination].path != -1)
            displayShortestPath(vertices[destination].path);
        cout << Map[destination] << " ";
        cout << "---->  ";
    }

    void mapping(string file_name)
    {
        ifstream file(file_name);
        int i;
        string s;
        while (file >> i >> s)
        {
            Map[i] = s;
        }
    }
};

map<int, string> Map; 