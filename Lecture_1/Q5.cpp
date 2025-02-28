#include <iostream>

using namespace std;

int main() {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;  // Read 5 real numbers

    // Initialize min and max with the first number
    double minNum = a, maxNum = a;

    // Compare and update min and max values
    if (b < minNum) minNum = b;
    if (b > maxNum) maxNum = b;

    if (c < minNum) minNum = c;
    if (c > maxNum) maxNum = c;

    if (d < minNum) minNum = d;
    if (d > maxNum) maxNum = d;

    if (e < minNum) minNum = e;
    if (e > maxNum) maxNum = e;

    // Print the sum of min and max numbers
    cout << (minNum + maxNum) << endl;

    return 0;
}
