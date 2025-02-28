#include <iostream>

using namespace std;

// Function to compute GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int m, n;

    // Read input values
    cin >> m >> n;

    // Compute and print the GCD
    cout << gcd(m, n) << endl;

    return 0;
}
