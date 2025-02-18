#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int k;
    double x;

    cout << "k: ";
    cin >> k;

    cout << "x: ";
    cin >> x;

    double alpha;

    alpha = ((k+x)/sqrt(fabs(x)))*pow(k, 2);

    int omega;

    omega = fabs(round(alpha)/10);

    cout << omega << endl;

    return 0;
}

