#include <iostream>
#include <vector>
using namespace std;

// Function to print the digits in the permutation
void printPermutation(const vector<int>& digits) {
    for (int digit : digits) {
        cout << digit;
    }
    cout << endl;
}

// Function to check if all digits in the vector are unique
bool hasUniqueDigits(const vector<int>& digits) {
    for (int i = 0; i < digits.size() - 1; i++) {
        for (int j = i + 1; j < digits.size(); j++) {
            if (digits[i] == digits[j]) return false; // Found duplicate digits
        }
    }
    return true; // All digits are unique
}

// Recursive function to generate permutations
void generatePermutations(int targetLength, int currentLength, vector<int>& currentDigits) {
    if (currentLength == targetLength) {
        return; // Base case: stop recursion when target length is reached
    }

    for (int digit = 1; digit <= targetLength; digit++) {
        if (currentLength < targetLength) {
            currentLength++;                 // Increase current depth
            currentDigits.push_back(digit);  // Add digit to current permutation
            generatePermutations(targetLength, currentLength, currentDigits); // Recursive call

            if (currentLength == targetLength && hasUniqueDigits(currentDigits)) {
                printPermutation(currentDigits); // Print valid permutation
            }

            currentDigits.pop_back();        // Backtrack
            currentLength--;                 // Decrease depth
        }
    }
}

int main() {
    int length;
    cin >> length;
    vector<int> permutation;
    generatePermutations(length, 0, permutation);
    return 0;
}
