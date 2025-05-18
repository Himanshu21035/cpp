#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// #define max=9999;
vector<vector<int>> dist={{0,20,42,25},
                          {20,0,30,34},
                          {42,30,0,10},
                          {25,34,10,0}
                        };
int n=4;
int VIS_ALL=(1<<n)-1;
vector<vector<int>> path((1<<n),vector<int>(n,-1));
int tsp(int mask,int pos){
    if(mask==VIS_ALL){
        return dist[pos][0];
    }
    int ans=INT_MAX;
    int bestNext=-1;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0){
            int newAns=dist[pos][i]+tsp(mask|(1<<i),i);
            ans=min(ans,newAns);
            bestNext=i;
        }
    }
    path[mask][pos]=bestNext;
    return ans;
}
void printPath(int mask,int pos){
    cout<<"path: 0";
    while(path[mask][pos]!=-1){
        int next=path[mask][pos];
        cout<<"->"<<next;
        mask=mask|(1<<next);
        pos=next;
    }
    cout<<"-> 0"<<endl;
}
int main(){
    int cost = tsp(1, 0); 
    cout << "Minimum TSP Cost: " << cost << endl;
    printPath(1, 0);
}