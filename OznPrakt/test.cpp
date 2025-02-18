#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ofstream file("file.txt");

    file << "Привет, мир!";

    file.close();

    return 0;
}