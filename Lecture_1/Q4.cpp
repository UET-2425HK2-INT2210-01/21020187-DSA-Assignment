#include <iostream>

using namespace std;

// Function to sort an array using Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;  // Read the number of elements

    int arr[n];  // Declare an array of size n
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Read the elements
    }

    bubbleSort(arr, n);  // Sort the array

    // Print the sorted numbers
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
