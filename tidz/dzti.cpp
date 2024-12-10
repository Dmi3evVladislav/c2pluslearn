#include <iostream>
#include <cmath>
using namespace std;
double calculate_sum(double E) {
    double S = 0.0;
    double prev_term = 0.0;
    double current_term = 0.0;
    int n = 1;
    int sign = 1;

    while (true) {
        current_term = sign * (1.0 / pow(n, 3));
        S += current_term;

        if (abs(current_term - prev_term) < E) {
            break;
        }

        prev_term = current_term;
        sign = -sign;
        n++;
    }
    return S;
}
int main() {
    double E;
    cout << "Input E (E < 1): ";
    cin >> E;
    if (E >= 1) {
        cout << "Number E must be smaller then 1." << endl;
    } else {
        double result = calculate_sum(E);
        cout << "Summ S: " << result << endl;
    }

    return 0;
}