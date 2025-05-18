#include <iostream>
#include <vector>
using namespace std;
bool isSafeToColor(int v, vector<vector<int>>& graph, vector<int>& colors, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && colors[i] == color) {
            return false;  
        }
    }
    return true;
}
bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& colors, int m, int v) {
    int n = graph.size();
    if (v == n) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafeToColor(v, graph, colors, c)) {
            colors[v] = c;
            if (graphColoringUtil(graph, colors, m, v + 1)) {
                return true;
            }
            colors[v] = 0;
        }
    }
    return false;
}
bool graphColoring(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0);
    if (graphColoringUtil(graph, colors, m, 0)) {
        cout << "Graph Coloring result with " << m << " colors:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " -> Color " << colors[i] << endl;
        }
        return true;
    }

    cout << "No solution with " << m << " colors." << endl;
    return false;
}
int main() {
    vector<vector<int>> graph = {
        {0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };
    int m = 3; 
    if (!graphColoring(graph, m)) {
        cout << "Trying with more colors..." << endl;
        m = 4;
        graphColoring(graph, m);
    }
    return 0;
}
