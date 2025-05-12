#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int peakElement(vector<int>& arr, int l, int h, int size, int& maxIdx) {
        if (l > h) {
            return -1; 
        }

        int mid = l + (h - l) / 2;

        
        if (arr[mid] > arr[maxIdx]) {
            maxIdx = mid;
        }

        
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && 
            (mid == size - 1 || arr[mid + 1] <= arr[mid])) {
            return mid; 
        }

        
        int leftResult = peakElement(arr, l, mid - 1, size, maxIdx);
        if (leftResult != -1) {
            return leftResult; 
        }

        int rightResult = peakElement(arr, mid + 1, h, size, maxIdx);
        if (rightResult != -1) {
            return rightResult; 
        }

        
        return -1;
    }

    int findPeakElement(vector<int>& nums) {
        int h = nums.size() - 1;
        int l = 0;
        int maxIdx = 0; 
        int peakIdx = peakElement(nums, l, h, nums.size(), maxIdx);

        
        return  peakIdx;
    }
};
int main(){
    Solution s;
    vector<int> arr={6,5,4,3,10};
    cout<<s.findPeakElement(arr);
    return 0;
}