#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double epsilon = 0.001;  
    double sum = 0.0;        
    double a;               
    int n = 1;              

    do {
        a = 1.0 / pow(2, n) + 1.0 / pow(3, n);  
        sum += a;                              
        n++;                                    
    } while (a >= epsilon);

    cout << "Summm = " << sum << endl;

    return 0;
}
