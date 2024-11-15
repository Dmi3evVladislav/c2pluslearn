#include <iostream>

using namespace std;

void shift_r(int mas[], int n, int k) {
    k = k % n;
    if (k == 0) return;
    int temp[n];
    for (int i = 0; i < n; ++i) {
        temp[(i + k) % n] = mas[i];
    }
    for (int i = 0; i < n; ++i) {
        mas[i] = temp[i];
    }
}

int main() {
    int mas[] = {1, 2, 3, 4, 5};
    int n = sizeof(mas) / sizeof(mas[0]);
    int k = 2;
    cout << "Start array: ";
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
    }
    cout << endl;
    shift_r(mas, n, k);
    cout << "Array after: ";
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
    }
    cout << endl;
    return 0;
}