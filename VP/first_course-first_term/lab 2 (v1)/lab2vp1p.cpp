#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a;
    double y;
    cout << "a: ";
    cin >> a;

    if(a <= 0) {
        y = -a;
    }
    // else if (a == 0) {
    //     y = 0;
    // }
    else if ((a > 0) && (a <= 2)){
        y = -pow(a, 2);
    }
    else {
        y = -4;
    }

    cout << y << endl;

    return 0;
}