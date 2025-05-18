#include <iostream>
#include <vector>
using namespace std;

// Function to find the index to replace using Optimal strategy
int findOptimal(vector<int>& pages, vector<int>& frame, int index) {
    int farthest = -1, pos = -1;
    for (int i = 0; i < frame.size(); i++) {
        int j;
        for (j = index; j < pages.size(); j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == pages.size()) {
            // Page is never used again
            return i;
        }
    }
    // If all pages will be used again, replace the farthest one
    return (pos == -1) ? 0 : pos;
}

int main() {
    int n, f;
    cout << "Enter number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;
    vector<int> frame;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;
        // Check if page is already in frame
        for (int j = 0; j < frame.size(); j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            if (frame.size() < f) {
                frame.push_back(pages[i]);
            } else {
                int pos = findOptimal(pages, frame, i + 1);
                frame[pos] = pages[i];
            }
            faults++;
        }

        // Display current frame status
        cout << "Frame: ";
        for (int x : frame)
            cout << x << " ";
        // Fill empty frames with -
        for (int k = frame.size(); k < f; k++)
            cout << "- ";
        cout << endl;
    }

    cout << "Total Page Faults: " << faults << endl;
    return 0;
}