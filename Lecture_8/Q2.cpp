#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numElements, targetSum;
    cin >> numElements >> targetSum;  // Read number of elements and the target sum

    vector<int> ages(numElements);  // Array storing the ages of students
    for (int i = 0; i < numElements; i++) {
        cin >> ages[i];  // Read each student's age
    }

    // dp[i] stores whether it is possible to form sum i using a subset of elements
    vector<bool> dp(targetSum + 1, false);
    dp[0] = true;  // A sum of 0 is always possible using the empty subset

    // Iterate through each age
    for (int i = 0; i < numElements; i++) {
        // Traverse backwards to avoid reusing the same element multiple times
        for (int j = targetSum; j >= ages[i]; j--) {
            if (dp[j - ages[i]]) {
                dp[j] = true;  // If sum (j - ages[i]) is possible, then sum j is also possible
            }
        }
    }

    // If dp[targetSum] is true, a subset with the target sum exists
    if (dp[targetSum]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
