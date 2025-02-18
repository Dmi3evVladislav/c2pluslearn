#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char input[1000];

    cin.getline(input, 1000);

    int colonPos = -1;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] == ':') {
            colonPos = i;
            break;
        }
    }
    if (colonPos == -1) {
        cout << "Colon not founded" << endl;
        return 1;
    }
    int count = 0;
    for (int i = colonPos + 1; input[i] != '\0'; ++i) {
        if (input[i] == '*') {
            ++count;
        }
    }
    cout << "Number of '*' symbols after colon: " << count << endl;
    return 0;
}

