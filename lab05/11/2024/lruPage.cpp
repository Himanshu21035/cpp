#include<bits/stdc++.h>
using namespace std;
void printVec(vector<int> v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> req={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2,1,2,0,1,7,0,1};
    int frameSize=3;
    int reqSize=req.size();
    vector<int> frame;
    int i=0;
    int curr=0;
    int hit=0,miss=0;
    while(i<reqSize){
        int found=false;
        int idx=0;
        for(int j=0;j<frame.size();j++){
            if(frame[j]==req[i]){
                idx=j;
                found=true;
                break;
            }
        }
        if(found){
            int temp=req[i];
            frame.erase(frame.begin()+idx);
            frame.push_back(temp);
            hit++;
            cout<<"hit"<<endl;
        }else{
            miss++;
            cout<<"miss"<<endl;
            if(curr<frameSize){
                frame.push_back(req[i]);
                curr++;
            }else{
                frame.erase(frame.begin()+0);
                frame.push_back(req[i]);
            }
        }
        printVec(frame);
        i++;
    }
    cout<<hit<<" "<<miss<<endl;
}