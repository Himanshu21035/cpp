#include<iostream>
#include<vector>
using namespace std;
void minmaxfn(vector<int> arr,int i,int j,vector<int> &minmax){
    if(i==j){
        minmax.push_back(arr[i]);
        minmax.push_back(arr[i]);
    }
    else if((j-i)==1){
        if(arr[i]>arr[j]){
            minmax.push_back(arr[j]);
            minmax.push_back(arr[i]);
        }
        else{
            minmax.push_back(arr[i]);
            minmax.push_back(arr[j]);
        }
    }
    else{
        int mid=i+(j-i)/2;
        vector<int> left,right;
        minmaxfn(arr,i,mid,left);
        minmaxfn(arr,mid+1,j,right);
        int leftmin=left[0], leftmax=left[1];
        int rightmin=right[0],rightmax=right[1];
        minmax.push_back(min(leftmin, rightmin));
        minmax.push_back(max(leftmax, rightmax));
    }
}
int main() {
    vector<int> arr = {12, 3, 5, 7, 19, -1};
    vector<int> minmax;
    minmaxfn(arr, 0, arr.size() - 1, minmax);
    cout << "Minimum value: " << minmax[0] << endl;
    cout << "Maximum value: " << minmax[1] << endl;
    return 0;
}