#include <iostream>
#include <cmath>
using namespace std;
struct CartesianPoint {
    double x;
    double y; 
};

struct PolarPoint {
    double r;
    double theta;
};

PolarPoint cartesianToPolar(const CartesianPoint& cartesian) {
    PolarPoint polar;
    polar.r = sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y);
    polar.theta = atan2(cartesian.y, cartesian.x);
    return polar;
}

int main() {
    CartesianPoint cartesian;

    cout << "Dekart cords (x, y): ";
    cin >> cartesian.x >> cartesian.y;

    PolarPoint polar = cartesianToPolar(cartesian);

    cout << "Polar cords: radius = " << polar.r << ", corner = " << polar.theta << " radian" << endl;
    return 0;
}
