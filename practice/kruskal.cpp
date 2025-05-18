#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u,v,weight;
    
};

vector<vector<int>> mst;

bool hasCycle(int src,unordered_set<int> &visited){
    unordered_map<int,int> parent;
    queue<int> q;
    visited.insert(src);
    q.push(src);
    parent[src]=-1;
    while(!q.empty()){
        int node=q.front();q.pop();
        for(int neigh: mst[node]){
            if(!visited.count(neigh)){
                visited.insert(neigh);
                q.push(neigh);
                parent[neigh]=node;
            }else if(neigh!=parent[node]){
                return true;
            }
        }
    }
    return false;
}
vector<Edge> kruskal(vector<Edge> graph,int V){
    mst.resize(V);
    vector<Edge> msg;
    auto cmp=[](Edge a,Edge b){ return a.weight>b.weight; };
    priority_queue<Edge,vector<Edge>,decltype(cmp)> pq(cmp,graph);
    while(!pq.empty()&&msg.size()<V){
        Edge edge=pq.top();pq.pop();
        mst[edge.u].push_back(edge.v);
        mst[edge.v].push_back(edge.u);
        unordered_set<int> visited;
        bool cycle = false;
        for(int i=0;i<V;i++){
            if(!visited.count(i)){
                if(hasCycle(i,visited)) {
                    cycle=true;
                    break;
                }
            }
        }
        if(cycle){
            mst[edge.u].pop_back();
            mst[edge.v].pop_back();
        }else{
            msg.push_back(edge);
        }
    }
    return msg;
}

int main() {
    int V = 5;
    vector<Edge> graph = {
    {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
    {1, 3, 15}, {2, 3, 4}, {3, 4, 2}
};

    vector<Edge> result = kruskal(graph, V);

    cout << "Edges in MST:\n";
    for (Edge e : result) {
        cout << e.u << " - " << e.v << " : " << e.weight << "\n";
    }

    return 0;
}