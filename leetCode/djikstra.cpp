#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Graph {
    int size;
    vector<vector<int>> adjMat;
    vector<int> soln;
    vector<bool> blChk;

public:
    Graph(int n) : size(n), adjMat(n, vector<int>(n, 0)), soln(n, INT_MAX), blChk(n, false) {}

    // Add an edge with a weight
    void addEdge(int s, int d, int wt) {
        adjMat[s][d] = wt;
    }
    void minDis(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        soln[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();
            if (blChk[u]) continue;
            blChk[u] = true;
            for (int v = 0; v < size; v++) {
                int weight = adjMat[u][v];
                if (weight > 0) {
                    if (soln[u] + weight < soln[v]) {
                        soln[v] = soln[u] + weight;
                        pq.push({soln[v], v});
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (soln[i] == INT_MAX) {
                cout << "Node " << i << " is unreachable from source." << endl;
            } else {
                cout << "Shortest distance from " << src << " to " << i << " is " << soln[i] << endl;
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 nodes
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 3);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 0, 7);

    g.minDis(0); // Find shortest paths from node 0

    return 0;
}
