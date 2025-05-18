#include<bits/stdc++.h>
using namespace std;        
bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, int parent) {
    visited[node] = 1;
    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            if (dfs(neighbor, graph, visited, node)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}bool hasCycle(int n, vector<vector<int>>& graph) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, graph, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n = 4;
    vector<vector<int>> graph(n);
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(0);
    if (hasCycle(n, graph)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }
    return 0;
}
