#include<iostream>
#include<vector>
#include<climits>
using namespace std;
double findMid(vector<int> &v){
    int size=v.size();
    double mid1;
    if(size==0){
        return -1.0;
    }
    if(size==1){
        return v[0];
    }
    else{
        if(size%2!=0){
            int x=(size+1)/2;
            return v[x];
        }
        else{
            int x=(size+2)/2;
            int y=(size)/2;
            mid1=(v[x-1]+v[y-1])/2.0;
            return mid1;
        }
    }
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s,s1;
        double mid1,mid2;
        double m1=findMid(nums1);
        double m2=findMid(nums2);
        if(m1==-1.0 || m2==-1.0){
            if(m1==-1){
                return m2;
            }
            else{
                return m1;
            }
        }
        else{
             if (nums1.size() > nums2.size()) {
                return findMedianSortedArrays(nums2, nums1);
                }

            int m = nums1.size(), n = nums2.size();
            int mid2 = n / 2; 
            int mid1 = 0; 

            while (true) {
        
             int leftElements = mid1 + mid2;
             int requiredLeft = (m + n + 1) / 2; 
             if (leftElements == requiredLeft) {
            
                // int leftMax = (mid1 > 0 ? nums1[mid1 - 1] : -999);
                int leftMax,rightMin;
                if(mid1>0){
                    leftMax=nums1[mid1-1];
                }
                else{
                    leftMax=INT_MIN;
                }
                if(mid1<m){
                    
                }
                int rightMin = (mid1 < m ? nums1[mid1] : 1010101);
                if (mid2 > 0) leftMax = max(leftMax, nums2[mid2 - 1]);
                if (mid2 < n) rightMin = min(rightMin, nums2[mid2]);
            
            return (m + n) % 2 == 0 ? (leftMax + rightMin) / 2.0 : leftMax;
        }
        else if (leftElements < requiredLeft) {
            // Move mid2 to the right until a larger number is found
            if (mid2 < n && (mid1 >= m || nums2[mid2] < nums1[mid1])) {
                mid2++;
            } else {
                mid1++;
            }
        }
        else {
            // Move mid1 and mid2 to the left if we have too many elements
            if (mid1 > 0 && (mid2 == 0 || nums1[mid1 - 1] > nums2[mid2 - 1])) {
                mid1--;
            } else {
                mid2--;
            }
        }
    }
        }
    }
double findMid(vector<int> &v){
    int s=v.size();
    if(s==1){
        return (double)v[0];
    }
    else{
        if(s%2==0){
            int x=(s+2)/2;
            int y=(s)/2;
            double mid1=(v[x-1]+v[y-1])/2.0;
            return mid1;
        }
        else{
            int x=(s+1)/2;
            double mid1=(v[x-1])/2.0;
            return mid1;
        }
    }
}

double findMedian(vector<int> &nums1,vector<int> &nums2){
    int s1=nums1.size();
    int s2=nums2.size();
    if(s1==0||s2==0){
        if(s1==0){
            return findMid(nums1);
        }
        else{
            return findMid(nums2);
        }        
    }
    int l1=0;
    int h1=s1-1;
    int l2=0;
    int h2=s2-1;
    int countl =0;
    int countr=0;
    if((s1+s2) %2 !=0){
        countl = (s1+s2)/2;
    }
    else{
        // count1 = (s1+s2)/2-1;
        // count2 = (s1+s2+2)/2-1;
    }
    while(l1<=h1 && l2<=h2){
        int mid1=l1+(h1-l1)/2;
        int mid2=l2+(h2-l2)/2;
        if(nums1[mid1]>nums2[mid2]){
            if(nums2[mid2+1]>nums1[mid1]){
                countl=l1;
            }
        }
    }
}
int main(){
    vector<int> v1,v2;
    v1={};
    v2={1};
    cout<<v1.size();
    double ans= findMedianSortedArrays(v1,v2);
    cout<<"answer is: "<<ans;
}