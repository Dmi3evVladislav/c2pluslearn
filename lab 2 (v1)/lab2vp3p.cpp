#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m;
    cout << "m: ";
    cin >> m;

    switch (m) {
        case 1:
        case 2:
        cout << (log(fabs(m+pow(m,2))) + sqrt(14)) << endl;
        break;
        case 3: 
        cout << ((m+3)/log(m)) << endl;
        break;
        case 4:
        case 7: 
        cout << (pow(m, 3) + 2*(pow(m, 2) + 1)) << endl;
        break;
        case 5: 
        cout << (744-pow(m, 2)*pow(sin(m),2)) << endl;
        break;
        case 6: 
        cout << (log(fabs(1+sqrt(m)))) << endl;
        break;
        default:
        cout << "[1, 7] doesn't include number: " << m << endl;
        break;
    }

    return 0;
}