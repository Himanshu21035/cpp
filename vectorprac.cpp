#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector <int> v{1,3,2,4,3,4,1,6};;
    vector<int> ans;
    int ts=7;
    // int arr[8]={1,3,2,4,3,4,1,6};
    // int y = sizeof(arr)/sizeof(arr[0]);
    int sz=8;
    for(int i=0;i<sz;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    
    
    // for(int i=0;i<y;i++){
    //     cout<<arr[i];
    // }
    // for(int i=0;i<y;i++){
    //     for(int j=i;j<y;j++){
    //         if(arr[i]+arr[j]==ts){
    //             v.push_back(arr[i]);
    //             v.push_back(arr[j]);
    //         }
    //     }
    // }


    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}