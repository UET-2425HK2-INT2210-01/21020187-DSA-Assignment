#include <iostream>
using namespace std;

// Recursive function to calculate the nth Fibonacci number
int calculateFibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return calculateFibonacci(n - 1) + calculateFibonacci(n - 2);
}

int main() {
    int number;
    // Read input number from user
    cin >> number;
    // Print the nth Fibonacci number
    cout << calculateFibonacci(number);
    return 0;
}
