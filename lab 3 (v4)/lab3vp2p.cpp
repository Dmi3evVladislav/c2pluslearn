#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double S;
    double x;               
    int n;         

    cout << "n: "; 
    cin >> n;  

    cout << "x: ";
    cin >> x;

    for (int i = 1; i <= n; ++i) {
        S += sin(pow(x, i));
    }

    cout << "S = " << S << endl;

    return 0;
}
