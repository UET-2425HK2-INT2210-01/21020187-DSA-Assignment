#include <iostream>
using namespace std;

// Recursive function to calculate the sum of digits of a number
int calculateDigitSum(int number) {
    if (number == 0) return 0;
    return number % 10 + calculateDigitSum(number / 10);
}

int main() {
    int inputNumber;
    // Read the number from user input
    cin >> inputNumber;
    // Print the sum of the digits
    cout << calculateDigitSum(inputNumber);
    return 0;
}
