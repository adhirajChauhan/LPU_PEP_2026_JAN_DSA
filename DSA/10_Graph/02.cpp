#include<iostream>
#include <list>
using namespace std;
 
int main()
{
    int n; //number of vertices
    int m; // number of edges

    cout << "Enter the number of vertices : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;

    unordered_map<int, list<int>> adjList;
    cout << "Enter edges (u , v) : " << endl;
    // cout << "\nAdjacency List : " << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout << "Adjacency List : " << endl;
    for(auto i : adjList){
        cout << i.first << " -> ";

        for(auto j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }

    
}