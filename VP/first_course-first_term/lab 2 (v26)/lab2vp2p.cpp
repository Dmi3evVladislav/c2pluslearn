#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double x;
    double y;

    cout << "x: ";
    cin >> x;

    cout << "y: ";
    cin >> y;

    if ((x < 0) && (y < 0)) {
        double memx;

        memx = x;
        x *= y;
        y *= memx;
    }
    else if ((x < 0) or (y < 0)) {
        x *= 0.5;
        y *= 0.5;
    }
    else if ((x+y) < 10) {

        if (x < y){
            x = pow(x, 2);
        }
        else if(y < x){
            y = pow(y, 2);
        }  
    }
    else {}
    cout << "x: "<< x << " y: " << y << endl;

}