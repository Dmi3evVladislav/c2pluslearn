#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char text[1000];
    cout << "Input text: ";
    cin.getline(text, 1000);

    char words[100][1000];
    int word_lengths[100];
    int word_count = 0;

    char *token = strtok(text, " ,.!?;:");
    while (token != nullptr && word_count < 100) {
        strcpy(words[word_count], token);
        word_lengths[word_count] = strlen(token);
        word_count++;
        token = strtok(nullptr, " ,.!?;:");
    }

    int min_length = word_lengths[0];
    for (int i = 1; i < word_count; ++i) {
        if (word_lengths[i] < min_length) {
            min_length = word_lengths[i];
        }
    }

    cout << "Words smalest length: ";
    for (int i = 0; i < word_count; ++i) {
        if (word_lengths[i] == min_length) {
            cout << words[i] << " ";
        }
    }
    cout << endl;

    return 0;
}