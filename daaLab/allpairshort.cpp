// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// const int INF = INT_MAX;

// void floydWarshall(vector<vector<int>>& graph) {
//     int n = graph.size();
    
//     // Create a distance matrix initialized with graph values
//     vector<vector<int>> dist = graph;

//     // Run Floyd-Warshall Algorithm
//     for (int k = 0; k < n; ++k) {
//         for (int i = 0; i < n; ++i) {
//             if (dist[i][k] == INF) continue; // skip if unreachable
//             for (int j = 0; j < n; ++j) {
//                 if (dist[k][j] == INF) continue; // skip if unreachable
//                 if (dist[i][j] > dist[i][k] + dist[k][j]) {
//                     dist[i][j] = dist[i][k] + dist[k][j];
//                 }
//             }
//         }
//     }

//     // Print the result
//     cout << "All-Pairs Shortest Distances:\n";
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (dist[i][j] == INF)
//                 cout << "INF ";
//             else
//                 cout << dist[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     vector<vector<int>> graph = {
//         {0,   5,  INF, 10},
//         {INF, 0,   3, INF},
//         {INF, INF, 0,   1},
//         {INF, INF, INF, 0}
//     };

//     floydWarshall(graph);

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX-100;
void fw(vector<vector<int>> &graph){
    vector<vector<int>> dist=graph;
    int n=graph.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dist[j][i]<INF&&dist[i][k]<INF){
                if(dist[j][k]>dist[j][i]+dist[i][k]){
                    dist[j][k]=dist[j][i]+dist[i][k];
                }
                }
            }
        }
    }
    //negative cycle detection 
    for(int i=0;i<n;i++){
        if(dist[i][i]<0){
            cout<<"negative cycle:"<<endl;
            return;

        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    vector<vector<int>> graph = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    fw(graph);

    return 0;
}