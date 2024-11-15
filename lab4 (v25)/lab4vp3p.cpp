#include <iostream>

using namespace std;

int main() {

    int matrix[5][5] = {
        {2, 3, 3, 4, 5},
        {1, 4, 2, 6, 1},
        {1, 1, 2, 4, 2},
        {1, 4, 2, 1, 5},
        {4, 1, 5, 2, 3},
    };

    int max_sum = matrix[0][0];

    for (int k = 0; k < 5; ++k) {
        int sum = 0;
        for (int i = 0; i <= k; ++i) {
            sum += matrix[i][k - i];
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    for (int k = 3; k >= 0; --k) {
        int sum = 0;
        for (int i = 0; i < 5 - k; ++i) {
            sum += matrix[k + i][4 - i];
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    cout << "Max summ parallel: " << max_sum << endl;

    return 0;
}