#include <iostream>
#include <cmath>
using namespace std;

// Function to compute the Greatest Common Divisor (GCD) using Euclid's algorithm
int computeGCD(int larger, int smaller) {
    if (larger % smaller == 0) {
        return smaller; // If there's no remainder, smaller is the GCD
    }
    return computeGCD(smaller, larger % smaller); // Recursive call with swapped values
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    // Ensure we always pass the larger number first
    int gcd = computeGCD(max(num1, num2), min(num1, num2));
    cout << gcd;

    return 0;
}
