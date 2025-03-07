#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    int A[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = 0; // Variable to count pairs

    // Iterate through each pair (i, j) with i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                count++; // Increment count if elements are equal
            }
        }
    }

    // Print the result
    cout << count << endl;

    return 0;
}