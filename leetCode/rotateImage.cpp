#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Start from j = i+1 to avoid double swap
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
        cout<<"[";
        for (int i = 0; i < matrix.size(); i++) { 
            cout<<"[";
        for (int j = 0; j < matrix[i].size(); j++) { // Traverse columns
            
            if(j!=n-1){
                cout << matrix[i][j] << ","<<" ";
            }
            else{
                cout << matrix[i][j] <<" ";
            }
        }
        if(i!=n-1){
            cout<<"] ,";
        }
        else{
            cout<<"]";
        }
        
    }
    cout<<"]";
    }
int main(){
    vector<vector<int>> vec={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < vec.size(); i++) { // Traverse rows
        for (int j = 0; j < vec[i].size(); j++) { // Traverse columns
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    rotate(vec);

}