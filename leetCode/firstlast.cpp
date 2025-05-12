#include<iostream>
using namespace std;
#include<vector>
vector<int> searchRange(vector<int>& nums, int target) {
      int l=0;
      int h=nums.size()-1;
      int st=-1;
      int end=-1;
      vector<int> ans;
      while(l<=h ){
        int mid=l+(h-l)/2;
         if (nums[mid] < target) { 
            l = mid + 1;
        }
        else if (nums[mid] > target) {
            h = mid - 1;
        }
        else {  
            end = mid; 
            l = mid + 1; 
        }
      }
      l=0;
      h=nums.size()-1;
      while(l<=h){
        int mid=l+(h-l)/2;
         if (nums[mid] < target) { 
            l = mid + 1;
        }
        else if (nums[mid] > target) {
            h = mid - 1;
        }
        else {  
            st = mid; 
            h = mid - 1; 
        }
      }
    ans.push_back(st);
    ans.push_back(end);
    return ans;
      
}

int main(){

    vector<int> arr={};
    int target=2;
    vector<int> v;
    
    v=searchRange(arr,target);
    for (int num : v) {
        cout << num << " ";
    }
    
    return 0;
}