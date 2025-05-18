#include<bits/stdc++.h>
using namespace std;
void bfsShortestPath(int n, vector<vector<int>>& graph, int source) {
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (distance[neighbor] == INT_MAX) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
    cout << "Shortest distances from node " << source << " to all other nodes:\n";
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            cout << "Node " << i << ": No path\n";
        } else {
            cout << "Node " << i << ": " << distance[i] << " edges\n";
        }
    }
}
int main() {
    int n = 6; 
    vector<vector<int>> graph(n);
    graph[0] = {1, 2,3};
    graph[1] = {3, 4};
    graph[2] = {0, 5};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};
    int source = 0;
    bfsShortestPath(n, graph, source);
    return 0;
}
