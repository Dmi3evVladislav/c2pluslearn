#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a;
    double b;

    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    if ((a == -10) and (b == -10)) {
        a = 1;
        b = 1;
    }
    else if ((a < 0) and (b < 0)) {
        a = 0;
        b = 0;
    }
    else {
        if (a<b) {
            a *= 1000;
        }
        else if(b>a) {
            b *= 1000;
        }
    }

    cout << a << " " << b << endl;
    return 0;
}