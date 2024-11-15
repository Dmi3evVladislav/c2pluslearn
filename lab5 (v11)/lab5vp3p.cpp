#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool isConsonant(char ch) {
    ch = tolower(ch);
    return (ch >= 'a' && ch <= 'z') && !isVowel(ch);
}

void extractWords(char* str, bool (*predicate)(char), char* result) {
    char* word = strtok(str, " ");
    while (word != nullptr) {
        if (predicate(word[0])) {
            strcat(result, word);
            strcat(result, "  ");
        }
        word = strtok(nullptr, " ");
    }
}

int main() {
    char str1[] = "apple orange banana pear";
    char str2[] = "car dog cat elephant";
    char str3[256] = "";

    extractWords(str1, isVowel, str3);
    extractWords(str2, isConsonant, str3);

    cout << "Result: " << str3 << endl;

    return 0;
}