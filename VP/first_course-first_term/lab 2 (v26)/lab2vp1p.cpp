#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double a;
    double y;

    cout << "a: ";
    cin >> a;

    if (a <= 0) {
        y = 1;
    }
    else if (a <= M_PI/2) {
        y = cos(a);
    }
    else {
        y = a - M_PI/2;
    }
    
    cout << "y: " << y << endl;
    return 0;
}