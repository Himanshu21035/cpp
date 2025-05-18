#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    vector<vector<pair<int,int>>> adj(n);
    adj[0].push_back({1, 4});
adj[0].push_back({2, 1});
adj[2].push_back({1, 2});
adj[1].push_back({3, 1});
adj[2].push_back({3, 5});
adj[3].push_back({4, 3});
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> ans(n,INT_MAX);
    pq.push({0,0});
    ans[0]=0;
    while(!pq.empty()){
        int node=pq.top().second,wt=pq.top().first;pq.pop();
        if(wt>ans[node]) continue;
        for(auto neigh: adj[node]){
            if(ans[neigh.first]>ans[node]+neigh.second){
                ans[neigh.first]=ans[node]+neigh.second;
                pq.push({neigh.second,neigh.first});
            }
        }
    }
    cout<<ans[n-1];
}