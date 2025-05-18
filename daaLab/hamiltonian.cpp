#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph=  {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};
int n=4;
int VIS_ALL=(1<<n)-1;
vector<vector<int>> path(1<<n,vector<int>(n,-1));
int start=0;
bool ham(int mask,int pos){
    if(mask==VIS_ALL) return graph[pos][start]==1;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0 && graph[pos][i]){
            if(ham(mask|1<<i,i)){
                path[mask][pos]=i;
                return true;
            }
        }
    }
    return false;
}
void printPath(int mask,int pos){
    cout<<"path: "<<pos;
    while(path[mask][pos]!=-1){
        int next=path[mask][pos];
        cout<<"->"<<next;
        mask=mask|1<<next;
        pos=next;
    }
}
int main(){
    if (ham(1, 0)) {
        cout << "Hamiltonian Cycle Exists!" << endl;
        printPath(1, 0);
    } else {
        cout << "No Hamiltonian Cycle Found." << endl;
    }
}