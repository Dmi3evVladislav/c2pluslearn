#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

int main(){
    double x;
    double y;

    cout << "x: ";
    cin >> x;

    cout << "y: ";
    cin >> y;

    bool isInArea;

    isInArea = 
    (((pow(x, 2) + pow(y, 2)) <= 4) && ((y >= (-x+2)) || (y >= (x+2))))
    || 
    (((y <= 0) && (y >= -1)) && ((x >= -2) && (x <= 2)));

    //cout << (isInArea ? "TRUE" : "FALSE") << endl;
    cout << boolalpha << isInArea << endl;

    return 0;
}

