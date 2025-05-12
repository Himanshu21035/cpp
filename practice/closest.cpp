#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate Euclidean distance
float calculate(vector<int> a, vector<int> b) {
    float dis = pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2);
    return sqrt(dis);
}

// Function to find the minimum distance in a given range
float findminDis(vector<vector<int>> &v, int minIndex, int maxIndex) {
    float minDistance = INT_MAX;
    
    for (int i = minIndex; i <= maxIndex; i++) {
        for (int j = i + 1; j <= maxIndex; j++) {
            float dist = calculate(v[i], v[j]);
            minDistance = min(minDistance, dist);
        }
    }
    
    return minDistance;
}

// Divide and Conquer approach to find minimum distance
float minDis(vector<vector<int>> &v, int minIndex, int maxIndex) {
    if (maxIndex - minIndex + 1 <= 3) {
        return findminDis(v, minIndex, maxIndex);
    }

    int mid = minIndex + (maxIndex - minIndex) / 2;
    
    float leftMin = minDis(v, minIndex, mid);
    float rightMin = minDis(v, mid + 1, maxIndex);
    
    float minDistance = min(leftMin, rightMin);
    
    return minDistance;
}

int main() {
    vector<vector<int>> v = {{2, 3}, {12, 30}, {40, 50}, {5, 1},{12,10},{3,4}};
    
    // Sort points based on x-coordinate
    sort(v.begin(), v.end());
    
    int size = v.size() - 1;
    
    float minDistance = minDis(v, 0, size);
    
    cout << "Minimum Distance: " << minDistance << endl;
    
    return 0;
}

