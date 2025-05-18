#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u,v,w;
};
vector<vector<int>> help;
bool hasCycle(int src,unordered_set<int> &visited,int V){
    unordered_map<int,int> par;
    queue<int> q;
    q.push(src);
    visited.insert(src);
    par[src]=-1;
    while(!q.empty()){
        int node=q.front();q.pop();
        for(int neigh:help[node]){
            if(!visited.count(neigh)){
                 visited.insert(neigh);
                 par[neigh]=node;
                 q.push(neigh);

            }else if(neigh!=par[node]) return true;
        }
    }
    return false;
}
struct compare{
    bool operator()(Edge &a,Edge &b){
        return a.w>b.w;
    }
};
vector<Edge> kruskal(int V,vector<Edge> graph){
    help.resize(V);
    vector<Edge> mst;
    priority_queue<Edge ,vector<Edge>,compare> pq(graph.begin(),graph.end());
    while(!pq.empty() && mst.size()<V-1){
        Edge e=pq.top();pq.pop();
        help[e.u].push_back(e.v);
        help[e.v].push_back(e.u);
        bool cycle=false;
        unordered_set<int> visited;
        for(int i=0;i<V;i++){
            if(!visited.count(i)){
                if(hasCycle(i,visited,V)) cycle=true;
            }
        }
        if(cycle){
            help[e.u].pop_back();
            help[e.v].pop_back();
        }
        else{
            mst.push_back(e);
        }
    }
    return mst;
}
int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> mst = kruskal(V, edges);

    cout << "Edges in MST:\n";
    for (auto& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.w << "\n";
    }

    return 0;
}