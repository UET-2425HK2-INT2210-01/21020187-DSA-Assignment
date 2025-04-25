#include <iostream>
using namespace std;

// Optimized recursive function using binary exponentiation
int calculatePower(int base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent % 2 == 0) {
        int half = calculatePower(base, exponent / 2);
        return half * half;
    } else {
        return base * calculatePower(base, exponent - 1);
    }
}

int main() {
    int base, exponent;
    // Read base and exponent from user input
    cin >> base >> exponent;
    // Print the result of base raised to the power of exponent
    cout << calculatePower(base, exponent);
    return 0;
}
