#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Function to get the number of digits in the largest number
int getMaxDigits(const vector<int>& A) {
    int maxVal = *max_element(A.begin(), A.end());
    int digits = 0;
    while (maxVal > 0) {
        digits++;
        maxVal /= 10;
    }
    return digits;
}

void radixSort(vector<int>& A) {
    int n = A.size();

    // Step 1: Find the number of digits (d) in the largest element
    int d = getMaxDigits(A);

    // Step 2: Initialize 10 queues for digits 0–9
    queue<int> Q[10];

    // Step 3: Set D = 1
    int D = 1;

    // Step 4: For K = 1 to d (process digit positions)
    for (int k = 1; k <= d; k++) {

        // Step 4.1: D = D * 10 (move to next significant digit)
        D *= 10;

        // Step 4.2: Place elements in queues based on current digit
        for (int i = 0; i < n; i++) {
            int t = (A[i] % D) / (D / 10); // Extract digit at current place
            Q[t].push(A[i]);
        }

        // Step 4.5: Collect back from queues into array A
        int idx = 0;
        for (int i = 0; i < 10; i++) {
            while (!Q[i].empty()) {
                A[idx++] = Q[i].front();
                Q[i].pop();
            }
        }
    }
}

int main() {
    vector<int> A = {237, 146, 259, 105, 163, 254, 371, 189};

    cout << "Original Array:\n";
    for (int x : A) cout << x << " ";
    cout << "\n\n";

    radixSort(A);

    cout << "Sorted Array:\n";
    for (int x : A) cout << x << " ";
    cout << endl;

    return 0;
}