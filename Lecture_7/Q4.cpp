#include <iostream>
#include <vector>
using namespace std;

// Function to print a binary vector
void printBinary(const vector<int>& binaryVector) {
    for (int bit : binaryVector) {
        cout << bit;
    }
    cout << endl;
}

// Recursive function to generate all binary numbers of length 'length'
void generateBinaryNumbers(int length, int currentCount, vector<int>& currentBinary) {
    if (currentCount == length) {
        return; // Base case: stop recursion if the length is reached
    }

    for (int bit = 0; bit <= 1; bit++) {
        if (currentCount < length) {
            currentCount++;              // Increase the current length
            currentBinary.push_back(bit); // Add current bit (0 or 1)
            generateBinaryNumbers(length, currentCount, currentBinary); // Recurse deeper
            if (currentCount == length) {
                printBinary(currentBinary); // Print when complete binary number is formed
            }
            currentBinary.pop_back();    // Backtrack
            currentCount--;              // Decrease the current length back
        }
    }
}

int main() {
    int length;
    cin >> length;
    vector<int> binaryResult;
    generateBinaryNumbers(length, 0, binaryResult);
    return 0;
}
