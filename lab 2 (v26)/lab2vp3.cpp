#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int x;
    double y;

    bool isOutOfRange = false;

    cout << "x: ";
    cin >> x;

    switch (x) {
        case 0:
        case 1: 
            y = (pow(sin(x), 3) + sqrt(x/2.)); 
            break;
        case 2:
        case 3: 
            y = (fabs(x-5)/tan(x)); 
            break;
        case 4:
        case 5: 
            y = (sin(x+3)*log(x)); 
            break;
        case 6:
        case 7:
        case 8: 
            y = (exp(3*x) + fabs(tan(x))); 
            break;
        default: 
            isOutOfRange = true;
            break;
    }

    if (isOutOfRange) {
        cout << "Number: " << x << " is out of range." << endl;
    }
    else {
        cout << y << endl;
    }
}