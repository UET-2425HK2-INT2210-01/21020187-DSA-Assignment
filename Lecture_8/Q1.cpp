#include <iostream>
#include <vector>
using namespace std;

// Quick sort function using Hoare's partition scheme
void quickSort(vector<int> &array, int left, int right) {
    int i = left, j = right;
    int pivot = array[(left + right) / 2]; // Choose the middle element as pivot

    // Partition the array into two parts
    while (i <= j) {
        while (array[i] < pivot) ++i;
        while (array[j] > pivot) --j;

        if (i <= j) {
            swap(array[i], array[j]);
            ++i;
            --j;
        }
    }

    // Recursively sort the two halves
    if (left < j) quickSort(array, left, j);
    if (i < right) quickSort(array, i, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> inputArray(n); // Initialize vector to store input values

    // Read input values
    for (int i = 0; i < n; ++i) {
        cin >> inputArray[i];
    }

    // Call quick sort
    quickSort(inputArray, 0, n - 1);

    // Output the sorted array
    for (int num : inputArray) {
        cout << num << " ";
    }

    return 0;
}
