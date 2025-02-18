#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m;
    cout << "m: ";
    cin >> m;
    double value;
    bool isOutOfRange = false;

    switch (m) {
        case 1:
        case 2:
        value = log(fabs(m+pow(m,2))) + sqrt(14);
        break;
        case 3: 
        value = (m+3)/log(m);
        break;
        case 4:
        case 7: 
        value = pow(m, 3) + 2*(pow(m, 2) + 1);
        break;
        case 5: 
        value = 744-pow(m, 2)*pow(sin(m),2);
        break;
        case 6: 
        value = log(fabs(1+sqrt(m)));
        break;
        default:
        isOutOfRange = true;
        break;
    }
    if (!isOutOfRange) {
            cout << value << endl;
    }
    else {
        cout << "[1, 7] doesn't include number: " << m << endl;
    }

    return 0;
}