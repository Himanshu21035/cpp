#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    static bool compare(pair<double, int>& p1, pair<double, int>& p2) {
        return p1.first > p2.first;  
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double, int>> pw(n);
        
        for (int i = 0; i < n; i++) {
            double valuePerWeight = (double)val[i] / wt[i];  
            pw[i] = {valuePerWeight, i};  
        }
        sort(pw.begin(), pw.end(), compare);

        double profit = 0.0;
        int i = 0;

        while (i < n && capacity >= wt[pw[i].second]) {
            capacity -= wt[pw[i].second]; 
            profit += val[pw[i].second]; 
            i++;  
        }
        if (i < n && capacity > 0) {
            profit += val[pw[i].second] * ((double)capacity / wt[pw[i].second]);
            capacity = 0;  
        }

        return profit;  
    }
};

int main() {
    Solution solution;
    
    vector<int> val = {1, 5, 7, 2, 7, 10};
    vector<int> wt = {4, 9, 6, 3, 7, 3};    
    int capacity = 24;                      
    double maxProfit = solution.fractionalKnapsack(val, wt, capacity);
    cout << "Maximum profit in the fractional knapsack: " << maxProfit << endl;
    
    return 0;
}
