#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 1;
    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 1) {
            return true;
        }
        if (visited[neighbor] == 0 && dfs(neighbor, graph, visited)) {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}
bool hasCycle(int n, vector<vector<int>>& graph) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, graph, visited)) {
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
    graph[3].push_back(1);
    if (hasCycle(n, graph)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }
    return 0;
}
