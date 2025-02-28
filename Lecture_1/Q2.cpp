#include <iostream>

using namespace std;

class Point {
public:
    double x, y;
    Point() : x(0), y(0) {}  // Default constructor
    Point(double x, double y) : x(x), y(y) {}  // Constructor with parameters
};

class Line {
public:
    Point p1, p2;
    
    Line(Point p1, Point p2) : p1(p1), p2(p2) {}

    // Function to compute the intersection of two lines
    static string getIntersection(Line l1, Line l2, Point &intersection) {
        double x1 = l1.p1.x, y1 = l1.p1.y;
        double x2 = l1.p2.x, y2 = l1.p2.y;
        double x3 = l2.p1.x, y3 = l2.p1.y;
        double x4 = l2.p2.x, y4 = l2.p2.y;

        // Compute determinants
        double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

        if (denominator == 0) {  // Parallel or coincident lines
            // Check if they are coincident (infinite intersections)
            if ((y2 - y1) * (x3 - x1) == (x2 - x1) * (y3 - y1)) {
                return "MANY";
            }
            return "NO";
        }

        // Compute intersection point
        double px = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denominator;
        double py = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denominator;

        intersection = Point(px, py);
        return "YES";
    }
};

int main() {
    Point A, B, C, D;

    // Read input
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    Line AB(A, B);
    Line CD(C, D);

    Point intersection;
    string result = Line::getIntersection(AB, CD, intersection);

    if (result == "YES") {
        cout << intersection.x << " " << intersection.y << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
