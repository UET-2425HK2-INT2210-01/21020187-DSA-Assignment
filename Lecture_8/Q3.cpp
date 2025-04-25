#include <iostream>
using namespace std;

int main() {
    int numItems, maxWeight;
    cin >> numItems >> maxWeight;  // Read number of items and maximum total weight

    int weight[100], value[100];   // Arrays to store weights and values of items
    for (int i = 0; i < numItems; i++) {
        cin >> weight[i] >> value[i];  // Read each item's weight and value
    }

    int dp[1001] = {0};  // dp[i] = maximum total value for weight limit i

    // Process each item
    for (int i = 0; i < numItems; i++) {
        // Iterate backwards to avoid overwriting previous states
        for (int j = maxWeight; j >= weight[i]; j--) {
            // Update dp[j] if including current item gives a better value
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[maxWeight] << endl;  // Output the maximum value that fits within the weight limit
    return 0;
}
