#include<bits/stdc++.h>
using namespace std;
void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, stack<int>& st) {
    vis[u] = true;
    for (int v : g[u]) if (!vis[v]) dfs(v, g, vis, st);
    st.push(u);
}
vector<int> topoSort(int n, vector<vector<int>>& g) {
    vector<bool> vis(n, false); stack<int> st;
    for (int i = 0; i < n; i++) if (!vis[i]) dfs(i, g, vis, st);
    vector<int> res;
    while (!st.empty()) res.push_back(st.top()), st.pop();
    return res;
}
int main() {
    vector<vector<int>> g = {
        {2,1}, {5}, {3}, {4}, {4}, {}
    };
    auto order = topoSort(g.size(), g);
    for (int x : order) cout << x << " ";
    cout << endl;
}
