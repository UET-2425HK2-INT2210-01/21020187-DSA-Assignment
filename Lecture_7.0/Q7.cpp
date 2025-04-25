#include <iostream>
using namespace std;

// Recursive function to reverse a number using a helper parameter
int reverseNumber(int number, int reversed = 0) {
    if (number == 0) return reversed;
    return reverseNumber(number / 10, reversed * 10 + number % 10);
}

int main() {
    int inputNumber;
    // Read the number from user input
    cin >> inputNumber;
    // Print the reversed number
    cout << reverseNumber(inputNumber);
    return 0;
}
