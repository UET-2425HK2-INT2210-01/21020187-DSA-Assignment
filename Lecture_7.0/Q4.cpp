#include <iostream>
using namespace std;

// Recursive function to calculate x raised to the power of n
int calculatePower(int base, int exponent) {
    if (exponent == 0) return 1;
    return base * calculatePower(base, exponent - 1);
}

int main() {
    int base, exponent;
    // Read base and exponent from user input
    cin >> base >> exponent;
    // Print the result of base raised to the power of exponent
    cout << calculatePower(base, exponent);
    return 0;
}
