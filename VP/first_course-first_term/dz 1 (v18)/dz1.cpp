#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int const N = 6;
double arrA[N][N];
double arrB[N][N]; 
double arrC[N][N];
double arrD[N][N];
double arrE[N][N];

void output(double arr[N][N]);
void bubbleSort(double arr[]);
void createA();
void createB();
void createC();
void createD();
void createE();

int main() {
    
    cout << endl;
    createA();
    cout << "\nMatrix B:" << endl;
    createB();
    cout << "\nMatrix C:" << endl;
    createC();
    cout << "\nMatrix D:" << endl;
    createD();
    cout << "\nMatrix E:" << endl;
    createE();
    cout << endl;

    double max1 = arrE[0][0];
    double max2 = arrE[4][0];

    for (int j = 1; j < N; ++j) {
        if (arrE[0][j] > max1) {
            max1 = arrE[0][j];
        }
    }
    for (int j = 1; j < N; ++j) {
        if (arrE[4][j] > max2) {
            max2 = arrE[4][j];
        }
    }

    cout << "Max element in string 1: " << max1 << endl;
    cout << "Max element in string 2: " << max2 << endl;
    cout << endl;
    return 0;
}

void output(double arr[N][N]){
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < N; ++j) { 
            cout << setw(10) << arr[i][j] << "\t"; 
        } 
        cout << endl;
     }
}

void createA() {
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < N; ++j) { 
            arrA[i][j] = (i + j) * (1/tan(j+1)); 
        }
    }
    output(arrA);
}

void bubbleSort(double arr[]) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void createB() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arrB[i][j] = arrA[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        bubbleSort(arrB[i]);
    }
    output(arrB);
}

void createC() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j >= i) {
                arrC[i][j] = j - i + 1;
            } else {
                arrC[i][j] = 0;
            }
        }
    }
    output(arrC);
}

void createD() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arrD[i][j] = 0;
            for (int k = 0; k < N; k++) {
                arrD[i][j] += arrB[i][k] * arrC[k][j];
            }
        }
    }
    output(arrD);
}

void createE() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arrE[i][j] = arrD[i][j];
        }
    }

    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) {
            arrE[i+2][j+2] = arrD[i][j];
        }
    }
    for (int i = 2; i < 4; i++){
        for(int j = 2; j < 4; j++){
            arrE[i-2][j-2] = arrD[i][j];
        }
    }
    output(arrE);
}

