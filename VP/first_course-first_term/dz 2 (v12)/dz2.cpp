#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double f(double x, double y) {
    return sqrt(x * x + 9 * x * sqrt(y));
}

double P(int i) {
    if (i == 1) return 1;
    return i + 1 + sqrt(P(i - 1));
}

double h(int i, double z) {
    if (i == 1) return 4;
    return z * h(i - 1, z) - h(i - 1, z) / i;
}

void processSequences(int ni[], int mj[], int lk[], int size, double a, double b, double c) {
    for (int i = 0; i < size; ++i) {
        if (ni[i] % 2 == 0) ni[i] /= a;
        if (mj[i] % 5 == 0) mj[i] /= b;
        if (lk[i] % 3 == 0) lk[i] /= c;
    }
}

int main() {
    double s, t, z;
    cout << "Input s, t and z: ";
    cin >> s >> t >> z;

    double a = f(t, s + 2) - f(t, s);
    double b = f(t + 1, s * s) - f(s, s);
    double c = sqrt(abs(h(9, z)));

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    const int size = 10;
    int ni[size], mj[size], lk[size];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < size; ++i) {
        ni[i] = dis(gen);   
        mj[i] = dis(gen);
        lk[i] = dis(gen);
    }

    cout << "input sequences:" << endl;
    cout << "ni: ";
    for (int i = 0; i < size; ++i) cout << ni[i] << " ";
    cout << endl;
    cout << "mj: ";
    for (int i = 0; i < size; ++i) cout << mj[i] << " ";
    cout << endl;
    cout << "lk: ";
    for (int i = 0; i < size; ++i) cout << lk[i] << " ";
    cout << endl;

    processSequences(ni, mj, lk, size, a, b, c);

    cout << "process sequences:" << endl;
    cout << "ni: ";
    for (int i = 0; i < size; ++i) cout << ni[i] << " ";
    cout << endl;
    cout << "mj: ";
    for (int i = 0; i < size; ++i) cout << mj[i] << " ";
    cout << endl;
    cout << "lk: ";
    for (int i = 0; i < size; ++i) cout << lk[i] << " ";
    cout << endl;

    return 0;
}