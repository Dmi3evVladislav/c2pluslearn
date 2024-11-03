#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int const N = 6;
double arrA[N][N];
double arrB[N][N]; 
double arrC[N][N];
double arrD[N][N];

void output(double arr[N][N]);
void bubbleSort(double arr[]);
void createA();
void createB();
void createC();
void createD();

int main() {
    
    cout << endl;
    createA();
    cout << "\nMatrix B:" << endl;
    createB();
    cout << "\nMatrix C:" << endl;
    createC();
    cout << "\nMatrix D:" << endl;
    createD();

    cout << endl;
    return 0;
}