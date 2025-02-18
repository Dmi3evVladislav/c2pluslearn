#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Input elem count: ";
    cin >> n;

    int sequence[n];
    cout << "Array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        if (fabs(sequence[i]) <= i * i) {
            sum += sequence[i];
        }
    }

    cout << "Summ elements (|Ai| <= i^2): " << sum << endl;

    return 0;
}