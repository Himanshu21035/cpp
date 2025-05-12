#include<iostream>
#include<vector>
#include<string>
using namespace std;
 int maxArea(vector<int>& height) {
        int s = height.size();
        int i=0;
        int j=s-1;
        
        // while(i<=j && (j-1)!=(i+1)){
        //     while(height[j-1]>=height[j]  && (j-1)!=(i+1)){
        //         j--;
        //     }
        //     while(height[i+1]<=height[i]  && (j-1)!=(i+1)){
        //         i++;
        //     }
        // }
        long long int ans=0;;
        while(i<j){
            long long int water=(j-i)*min(height[j],height[i]);
            if(water>=ans){
                ans=water;
            }
            if(height[i]<height[j]){
                i++;
            }
            else if(height[i]>=height[j]){
                j--;
            }
        }
        
        return ans;


        
    }
    int main(){
        vector<int> v={1,8,6,2,5,4,8,3,7};
        int rain=maxArea(v);
        cout<<"rain Trapped is: "<<rain;
    }