#include <iostream>
using namespace std;

// Recursive function to calculate the sum from 1 to n
int calculateSum(int n) {
    if (n == 1) return 1;
    return n + calculateSum(n - 1);
}

int main() {
    int number;
    // Read input number from the user
    cin >> number;
    // Print the sum from 1 to the given number
    cout << calculateSum(number);
    return 0;
}
