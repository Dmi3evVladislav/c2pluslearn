#include <iostream>
#include <cstring>
using namespace std;

void printVerticalHistogram(const char* text) {
    int lengths[100] = {0};
    int maxLength = 0;

    char* word = strtok((char*)text, " \t\n");
    while (word != nullptr) {
        int len = strlen(word);
        lengths[len]++;
        if (len > maxLength) {
            maxLength = len;
        }
        word = strtok(nullptr, " \t\n");
    }

    for (int i = maxLength; i > 0; i--) {
        for (int j = 1; j <= maxLength; j++) {
            if (lengths[j] >= i) {
                cout << "  #";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }

    for (int i = 1; i <= maxLength; i++) {
        cout << "---";
    }
    cout << endl;
    for (int i = 1; i <= maxLength; i++) {
        cout << " " << i << " ";
    }
    cout << endl;
}

int main() {
    char text[1000];

    cout << "Input text: ";
    cin.getline(text, 1000);

    printVerticalHistogram(text);

    return 0;
}