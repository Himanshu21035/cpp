#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    int V; 
    vector<vector<pair<int, int>>> adjList;
    Graph(int n) : V(n), adjList(vector<vector<pair<int, int>>>(n)) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); 
    }
    void primMST() {
        // Vector to store the minimum weight edge for each vertex
        vector<int> key(V, INT_MAX);

        // To store parent vertices for MST
        vector<int> parent(V, -1);

        // To keep track of vertices included in MST
        vector<bool> inMST(V, false);

        // The nearest edge for each vertex (stores the minimum weight edge that connects the vertex to MST)
        vector<int> nearestEdge(V, INT_MAX);

        // Start from the 0th vertex
        key[0] = 0; // Start from the first vertex (0th vertex)
        nearestEdge[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            // Find the vertex with the smallest nearestEdge[v] which is not yet in MST
            int u = -1;
            int minKey = INT_MAX;

            for (int v = 0; v < V; v++) {
                if (!inMST[v] && nearestEdge[v] < minKey) {
                    minKey = nearestEdge[v];
                    u = v;
                }
            }

            // If u is -1, it means there is no valid edge remaining
            if (u == -1) break;

            // Include u in MST
            inMST[u] = true;

            // Update the nearestEdge for all adjacent vertices of u
            for (auto& edge : adjList[u]) {
                int v = edge.first;  // Neighbor vertex
                int weight = edge.second;  // Weight of edge u-v

                // If vertex v is not yet in MST and the edge weight is smaller than the current nearestEdge for v
                if (!inMST[v] && weight < nearestEdge[v]) {
                    nearestEdge[v] = weight;
                    parent[v] = u;  // Set u as the parent of v
                }
            }
        }

        // Print the edges in the MST and calculate the total weight of the MST
        cout << "Edges in the Minimum Spanning Tree (MST):\n";
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << "Vertex " << i << " - Parent: " << parent[i] << " with weight: " << nearestEdge[i] << endl;
            totalWeight += nearestEdge[i];
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    // Number of vertices in the graph
    int V = 5;
    
    // Create a graph with V vertices
    Graph g(V);
    
    // Add edges to the graph (u, v, weight)
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    
    // Call Prim's Algorithm to find the MST
    g.primMST();
    
    return 0;
}
