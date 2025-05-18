#include <iostream>
using namespace std;

const int P = 5; // Number of processes
const int R = 3; // Number of resources

int main() {
    int alloc[P][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max[P][R]   = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail[R]    = {3, 3, 2};

    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    bool finish[P] = {0};
    int safeSeq[P], work[R];
    for (int i = 0; i < R; i++) work[i] = avail[i];

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool possible = true;
                for (int j = 0; j < R; j++)
                    if (need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                if (possible) {
                    for (int j = 0; j < R; j++) work[j] += alloc[i][j];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is not in a safe state.\n";
            return 1;
        }
    }

    cout << "Safe sequence: ";
    for (int i = 0; i < P; i++) cout << "P" << safeSeq[i] << (i < P - 1 ? " -> " : "\n");
    return 0;
}