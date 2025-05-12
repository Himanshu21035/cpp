#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> conventionalMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}
vector<vector<int>> strassenMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid, 0)), A12(mid, vector<int>(mid, 0)),
                        A21(mid, vector<int>(mid, 0)), A22(mid, vector<int>(mid, 0));
    vector<vector<int>> B11(mid, vector<int>(mid, 0)), B12(mid, vector<int>(mid, 0)),
                        B21(mid, vector<int>(mid, 0)), B22(mid, vector<int>(mid, 0));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    vector<vector<int>> P1 = strassenMultiplication(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> P2 = strassenMultiplication(addMatrix(A21, A22), B11);
    vector<vector<int>> P3 = strassenMultiplication(A11, subtractMatrix(B12, B22));
    vector<vector<int>> P4 = strassenMultiplication(A22, subtractMatrix(B21, B11));
    vector<vector<int>> P5 = strassenMultiplication(addMatrix(A11, A12), B22);
    vector<vector<int>> P6 = strassenMultiplication(subtractMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> P7 = strassenMultiplication(subtractMatrix(A12, A22), addMatrix(B21, B22));

    vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(P1, P4), P5), P7);
    vector<vector<int>> C12 = addMatrix(P3, P5);
    vector<vector<int>> C21 = addMatrix(P2, P4);
    vector<vector<int>> C22 = addMatrix(subtractMatrix(addMatrix(P1, P3), P2), P6);

    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    // Strassen's Matrix Multiplication
    vector<vector<int>> C_strassen = strassenMultiplication(A, B);
    cout << "Strassen's Matrix Multiplication Result:" << endl;
    printMatrix(C_strassen);
    cout << endl;

    // Conventional Matrix Multiplication
    vector<vector<int>> C_conventional = conventionalMultiplication(A, B);
    cout << "Conventional Matrix Multiplication Result:" << endl;
    printMatrix(C_conventional);

    return 0;
}
