#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partitionIndex(vector<int> &arr,int l,int h){
    int pivot=l;
    int i=l+1;
    int j=h;
    while(i<=j){
        while(i <= h && arr[i]<arr[pivot]){
            i++;
        }
        while(j > l && arr[j]>=arr[pivot]){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[pivot]);
    return j;
}
int Quick(vector<int>& arr,int l,int h,int target){
    while(l<h){
        int pi=partitionIndex(arr,l,h);
        if(pi==target-1){
            return arr[pi];
        }
        else if(pi>(target-1)){
            return Quick(arr,l,pi-1,target);
        }
        else{
            return Quick(arr,pi+1,h,target);
        }
        
    }
    return -1;
}
int main(){
    vector<int> v={5,4,3,2,1};
    int h=v.size()-1;
    int ans=Quick(v,0,h,2);
    cout<<ans;
    // int i=0;
    // while(i<=h){
    //     cout<<v[i]<<endl;
    //     i++;
    // }
}