#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int M = 1024;
const int S = sizeof(long) + sizeof(int) + sizeof(char);

struct R {
    long o;
    int l;
    char d;
};

void crtIdx(const char* t, const char* i) {
    ifstream f(t, ios::in | ios::binary);
    ofstream idx(i, ios::out | ios::binary);

    if (!f || !idx) {
        cout << "Error opening file!" << endl;
        return;
    }

    char b[M];
    long o = 0;

    while (f.getline(b, M)) {
        R r;
        r.o = o;
        r.l = strlen(b);
        r.d = 0;
        idx.write((char*)&r, S);
        o = f.tellg();
    }

    f.close();
    idx.close();
}

void delStr(const char* i, int n) {
    fstream idx(i, ios::in | ios::out | ios::binary);

    if (!idx) {
        cout << "Error opening file!" << endl;
        return;
    }

    idx.seekg((n - 1) * S);
    R r;
    idx.read((char*)&r, S);
    r.d = 1;
    idx.seekp((n - 1) * S);
    idx.write((char*)&r, S);

    idx.close();
}

void prnStr(const char* t, const char* i) {
    ifstream f(t, ios::in | ios::binary);
    ifstream idx(i, ios::in | ios::binary);

    if (!f || !idx) {
        cout << "Error opening file!" << endl;
        return;
    }

    R r;
    int c = 1;

    while (idx.read((char*)&r, S)) {
        if (r.d == 0) {
            char b[M];
            f.seekg(r.o);
            f.read(b, r.l);
            b[r.l] = '\0';
            cout << c << ": " << b << endl;
        }
        c++;
    }

    f.close();
    idx.close();
}

int main() {
    const char* t = "text.txt";
    const char* i = "index.dat";

    crtIdx(t, i);
    delStr(i, 2);
    prnStr(t, i);

    return 0;
}