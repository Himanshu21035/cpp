#include <bits/stdc++.h>
#include<vector>
using namespace std;
void bfsTraversal(vector<vector<int>>& graph,int n,int node,vector<bool>& check,vector<int>&ans){
    check[node]=true;
    for(int neigh: graph[node]){
        if(!check[neigh]){
            bfsTraversal(graph,n,neigh,check,ans);
        }
    }
    ans.push_back(node);
}
vector<int> topoSort(vector<vector<int>>& graph,int n){
    vector<bool> check(n+1,false);
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!check[i]){
            bfsTraversal(graph,n,i,check,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){

}