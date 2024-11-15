#include <iostream>
using namespace std;

int main() {
    const int n = 15;
    int sequence[n];
    int count[1000] = {0};

    cout << "Input 15 natural numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
        count[sequence[i]]++;
    }

    cout << "Unic numbers: ";
    for (int i = 0; i < n; ++i) {
        if (count[sequence[i]] == 1) {
            cout << sequence[i] << " ";
            count[sequence[i]] = 0;
        }
    }
    cout << endl;

    return 0;
}

