#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

// Graph class
class Graph {
private:
    unordered_map<int, list<int>> adjList; // Adjacency List representation

public:
    // Add a vertex
    void addVertex(int v) {
        adjList[v] = list<int>();
    }

    // Add an edge between vertices u and v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Depth First Search (DFS) traversal
    void DFS(int start) {
        unordered_map<int, bool> visited;
        DFSUtil(start, visited);
        cout << endl;
    }

    // Helper function for DFS
    void DFSUtil(int v, unordered_map<int, bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // Breadth First Search (BFS) traversal
    void BFS(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();

            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Display the graph
    void display() {
        for (auto& pair : adjList) {
            cout << pair.first << ": ";
            for (int v : pair.second) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};
