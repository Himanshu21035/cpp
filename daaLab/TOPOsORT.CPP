#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& topoOrder) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, topoOrder);
        }
    }
    topoOrder.push(node);
}
vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n, false);
    stack<int> topoOrder;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, topoOrder);
        }
    }
    vector<int> result;
    while (!topoOrder.empty()) {
        result.push_back(topoOrder.top());
        topoOrder.pop();
    }
    return result;
}
int main() {
    int n = 6;
    vector<vector<int>> graph(n);
    graph[0].push_back(2);
    graph[0].push_back(1);
    graph[1].push_back(5);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(4);
    vector<int> topoOrder = topologicalSort(n, graph);
    cout << "Topological Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
