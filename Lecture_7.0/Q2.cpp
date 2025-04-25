#include <iostream>
using namespace std;

// Recursive function to calculate factorial of n
int calculateFactorial(int n) {
    if (n == 1) return 1;
    return n * calculateFactorial(n - 1);
}

int main() {
    int number;
    // Read input number from the user
    cin >> number;
    // Print the factorial of the input number
    cout << calculateFactorial(number);
    return 0;
}
