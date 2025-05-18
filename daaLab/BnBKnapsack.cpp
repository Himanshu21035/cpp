#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct Item {
    int weight;
    int profit;
    double ratio;
};
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}
double bound(int i, int n, int W, vector<Item>& items, int currWeight, int currProfit) {
    if (currWeight >= W) return 0;
    double result = currProfit;
    int totalWeight = currWeight;
    while (i < n && totalWeight + items[i].weight <= W) {
        totalWeight += items[i].weight;
        result += items[i].profit;
        i++;
    }
    if (i < n) {
        result += (W - totalWeight) * items[i].ratio;
    }
    return result;
}
void knapsack(int n, int W, vector<Item>& items) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    sort(items.begin(), items.end(), compare);
    int maxProfit = 0;
    vector<int> currItems;
    int currWeight = 0;
    int currProfit = 0;
    vector<int> bestItems;
    int i = 0;
    while (i < n) {
        if (currWeight + items[i].weight <= W) {
            currWeight += items[i].weight;
            currProfit += items[i].profit;
            currItems.push_back(i);
            maxProfit = max(maxProfit, currProfit);
        }
        if (bound(i, n, W, items, currWeight, currProfit) > maxProfit) {
            i++;
        } else {
            break; 
        }
    }
    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Items selected (0-based indices): ";
    for (int index : currItems) {
        cout << index << " ";
    }
    cout << endl;
}
int main() {
    int n = 4;
    int W = 10;
    vector<Item> items = {
        {2, 10, 0},  
        {3, 40, 0}, 
        {4, 50, 0},  
        {5, 70, 0}  
    };
    knapsack(n, W, items);
    return 0;
}
