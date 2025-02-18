#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double a, b;
    int c;

    cout << "a: ";
    cin >> a;
    
    cout << "b: ";
    cin >> b;

    cout << "c: ";
    cin >> c;

    double x;

    x =  (2 * cos(b-1/6.)) / (1/2. + pow(sin(a), 2.0));

    double y;

    y = 1 + pow(c, 2) / (3 + log(pow(c, 2) + 1)/5); 

    cout << "x: " <<  x << endl;
    cout << "y: " <<  y << endl;


    return 0;
}

