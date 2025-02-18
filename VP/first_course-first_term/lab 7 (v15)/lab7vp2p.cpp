#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

const int MLL = 1000;

bool startsAndEndsWithSameLetter(const char* line) {
    if (line[0] == '\0') {
        return false;
    }
    char firstChar = tolower(line[0]);
    char lastChar = tolower(line[strlen(line) - 1]);

    return isalpha(firstChar) && isalpha(lastChar) && firstChar == lastChar;
}

int main() {
    const char* filename = "input.txt";
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return 1;
    }

    char line[MLL];
    int count = 0;

    while (inputFile.getline(line, MLL)) {
        if (startsAndEndsWithSameLetter(line)) {
            count++;
        }
    }

    inputFile.close();

    cout << "Number of lines that start and end with the same letter: " << count << endl;

    return 0;
}