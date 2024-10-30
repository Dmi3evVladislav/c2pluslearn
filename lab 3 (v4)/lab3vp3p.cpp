#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
    double sum{};
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 50; j++){
            sum += (j-i+1.0)/(i+j);
        }
    }
    cout << "sum: " << sum << endl;

    return 0;
} 


