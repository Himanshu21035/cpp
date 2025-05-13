#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> req= {98, 183, 41, 122, 14, 124, 65, 67};
    int ans=0,min=0,max=199;
    unordered_set<int> reqSet;
    for(int i:req) reqSet.insert(i);
    int chp=53;
    for(int i=chp;i<=max;i++){
        if(reqSet.count(i)){
            reqSet.erase(i);
            ans+=abs(i-chp);
            chp=i;
        }
    }
    for(int i=chp;i>=min;i--){
        if(reqSet.count(i)){
            reqSet.erase(i);
            ans+=abs(i-chp);
            chp=i;
        }
    }
    cout<<ans<<endl;
}