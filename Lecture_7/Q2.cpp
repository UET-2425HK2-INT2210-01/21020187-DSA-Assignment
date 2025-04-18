#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum sum submatrix
void findMaxSumSubmatrix(vector<vector<int>> matrix, int totalRows, int totalCols) {
    int finalTop = 0, finalLeft = 0, finalBottom = 0, finalRight = 0;
    int maxSum = INT_MIN;

    for (int topRow = 0; topRow < totalRows; topRow++) {
        // Temporary array to store the sum of elements column-wise
        vector<int> columnSums(totalCols, 0);

        for (int bottomRow = topRow; bottomRow < totalRows; bottomRow++) {
            // Accumulate column sums between topRow and bottomRow
            for (int col = 0; col < totalCols; col++) {
                columnSums[col] += matrix[bottomRow][col];
            }

            // Apply Kadane's algorithm on the 1D array columnSums
            int currentSum = 0;
            int tempLeft = 0, tempRight = 0, startCol = 0;

            for (int col = 0; col < totalCols; col++) {
                if (currentSum < 0) {
                    currentSum = columnSums[col];
                    startCol = col;
                } else {
                    currentSum += columnSums[col];
                }

                if (currentSum > maxSum) {
                    maxSum = currentSum;
                    finalTop = topRow;
                    finalBottom = bottomRow;
                    finalLeft = startCol;
                    finalRight = col;
                }
            }
        }
    }

    // Output the result in 1-based indexing
    cout << finalTop + 1 << " " << finalLeft + 1 << " " << finalBottom + 1 << " " << finalRight + 1 << " " << maxSum;
}

int main() {
    string inputFilePath;
    cin >> inputFilePath;
    ifstream inputFile(inputFilePath);

    if (!inputFile) {
        cout << "File not found.";
        return 0;
    }

    int rowCount, colCount;
    inputFile >> rowCount >> colCount;

    vector<vector<int>> inputMatrix(rowCount, vector<int>(colCount));

    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            inputFile >> inputMatrix[row][col];
        }
    }

    findMaxSumSubmatrix(inputMatrix, rowCount, colCount);

    inputFile.close();
    return 0;
}
