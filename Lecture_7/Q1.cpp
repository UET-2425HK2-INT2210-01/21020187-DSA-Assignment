#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

// Function to print the vector
void printVector(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return;
}

// Bubble sort function
void bubbleSort(vector<int> &vec){ // Pass vector by reference
    for(int i = 0; i < vec.size() - 1; i++){
        // After each iteration, the largest elements bubble to the end
        for(int j = 0; j < vec.size() - i - 1; j++){
            // Swap adjacent elements if they are in the wrong order
            if(vec[j] > vec[j + 1]){
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main(){
    string filePath;
    cin >> filePath;
    ifstream inputFile(filePath);
    if(!inputFile){
        cout << "File not found" << endl;
    }else{
        vector<int> numbers;
        int number;
        while(inputFile >> number){
            numbers.push_back(number); // Add values from file to the vector
        }
        bubbleSort(numbers); // Call bubble sort
        printVector(numbers); // Print sorted values
    }

    return 0;
}
