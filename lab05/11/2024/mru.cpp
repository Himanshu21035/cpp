#include<bits/stdc++.h>
using namespace std;
void printVec(vector<int> v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> req={98, 183, 41, 122, 14, 124, 65, 67};
    int reqSize=req.size();
    int frame=3;
    int hit=0,miss=0;
    int i=0;
    vector<int> frameVec;
    int strt=0;
    while(i<reqSize){
        bool fnd=false;
        int idx=0;
        for(int j=0;j<frameVec.size();j++){
            if(frameVec[j]==req[i]){
                fnd=true;
                idx=j;
                break;
            }
        }
        if(fnd){
            frameVec.erase(frameVec.begin()+idx);
            frameVec.push_back(req[i]);
            hit++;
        }else{
            miss++;
            if(frameVec.size()<frame){
                frameVec.push_back(req[i]);
            }else{
                frameVec.pop_back();
                frameVec.push_back(req[i]);
            }
        }
        printVec(frameVec);
        i++;
    }
    cout<<hit<<" "<<miss<<endl;
}