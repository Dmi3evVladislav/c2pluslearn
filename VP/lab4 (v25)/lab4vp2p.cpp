#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double calculateArea(const Point vertices[], int n) {
    double area = 0.0;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }

    area = fabs(area) / 2.0;
    return area;
}

int main() {
    Point vertices[] = {
        {0.0, 0.0},
        {4.0, 0.0},
        {4.0, 3.0},
        {0.0, 3.0}
    };

    int n = sizeof(vertices) / sizeof(vertices[0]);

    double area = calculateArea(vertices, n);

    cout << "Area: " << area << endl;

    return 0;
}