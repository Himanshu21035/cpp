#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> req={ 98, 183, 41, 122, 14, 124, 65, 67};
    int reqSize=req.size();
    int chp=53;
    int ans=0,min=0,max=199;
    // bool left=true;
    int currNo=0;
    // vector<int> left,right;
    unordered_set<int> reqSet;
    unordered_set<int> visited;
    for(int i:req) reqSet.insert(i);
    // while(currNo<reqSize){
        for(int i=chp;i<max;i++){
            if(reqSet.count(i)){
                cout<<i<<endl;
                reqSet.erase(i);
                ans=ans+abs(i-chp);
                chp=i;
                currNo++;
            }           
        }
        
        if(true){
            ans+=abs(max-chp);
            cout<<"ans Added"<<endl;
        }
        chp=max;
        for(int i=max;i>=min;i--){
            if(reqSet.count(i)){
                cout<<i<<endl;
                reqSet.erase(i);
                ans+=abs(chp-i);
                chp=i;
                currNo++;
            }
        }
    // } 
    cout<<ans;
}