#include <iostream>

using namespace std;

void set(int some) {
    some = 7;
}

int main () {

    int a {0};

    set(a);

    cout << a;


    return 0;
}