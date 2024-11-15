#include <iostream>
#include <cmath>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void neumannSort(int arr[], int n) {
    int step = 1;
    while (step < n) {
        for (int i = 0; i < n; i += 2 * step) {
            int left = i;
            int mid = min(i + step - 1, n - 1);
            int right = min(i + 2 * step - 1, n - 1);
            merge(arr, left, mid, right);
        }
        step *= 2;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Input n (n >= 2): ";
    cin >> n;

    if (n < 2) {
        return 1;
    }

    int size = pow(2, n);
    int arr[size];

    cout << "Array's elements (2^n): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Start array: ";
    printArray(arr, size);

    neumannSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}