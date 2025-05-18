#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void printAns(vector<int> &v, vector<vector<string>> &answer, int n) {
        int i = 1;
        vector<string> mid;
        for (int k = 0; k < n; k++) {
            string s = "";
            for (int l = 0; l < n; l++) {
                if (l + 1 == v[i]) {
                    s += 'Q';
                } else {
                    s += '.';
                }
            }
            i++;
            mid.push_back(s);
        }
        answer.push_back(mid);
    }
    bool place(int k, int j, vector<int>& ans) {
        for (int a = 1; a < k; a++) {
            if (ans[a] == j || abs(ans[a] - j) == abs(a - k)) {
                return false;
            }
        }
        return true;
    }
    void placeQueen(int k, vector<int>& ans, int n, vector<int>& v, vector<vector<string>> &answer) {
        if (k == n + 1) {
            v = ans;
            printAns(v, answer, n);
            return;
        }
        for (int j = 1; j <= n; j++) {
            if (place(k, j, ans)) {
                ans[k] = j;
                placeQueen(k + 1, ans, n, v, answer);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> v;
        vector<vector<string>> answer;
        vector<int> ans(n + 1, 0); 
        placeQueen(1, ans, n, v, answer);
        return answer;
    }
};
int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(n);
    cout << "Total solutions: " << results.size() << endl;
    for (const auto& board : results) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
