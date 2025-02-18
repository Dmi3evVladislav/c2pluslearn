#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    int m;
    cout << "Natural m: ";
    cin >> m;
    srand(time(0));
    double x[m];
    for (int i = 0; i < m; ++i) {
        x[i] = 5 + (rand() % 6) + (rand() % 1000) / 1000.0;
    }
    cout << "Generated array:" << endl;
    for (int i = 0; i < m; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
    int max_k = 0;
    int current_k = 1;
    for (int i = 1; i < m - 1; ++i) {
        if ((x[i] > x[i + 1] && x[i + 1] < x[i + 2]) || (x[i] < x[i + 1] && x[i + 1] > x[i + 2])) {
            current_k += 1;
        } 
        else {
            if (current_k > max_k) {
                max_k = current_k;
            }
            current_k = 1;
        }
    }
    if (current_k > max_k) {
        max_k = current_k;
    }
    cout << "Length bigest saw: " << max_k << endl;
    return 0;
}