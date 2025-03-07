#include <iostream>
using namespace std;

// Algorithm 1: Using Library Function
int powerUsingLibrary(int n) {
    return pow(2, n);
}

// Algorithm 2: Using Bitwise Shift
int powerUsingBitShift(int n) {
    return 1 << n;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Using Library Function: " << powerUsingLibrary(n) << endl;
    cout << "Using Bitwise Shift: " << powerUsingBitShift(n) << endl;

    return 0;
}
