#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char text[1000];
    cout << "Input text: ";
    cin.getline(text, 1000);

    int total_word_length = 0;
    int word_count = 0;
    int total_punctuation_distance = 0;
    int punctuation_count = 0;
    bool in_word = false;
    int last_punctuation_position = -1;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            if (!in_word) {
                in_word = true;
                word_count++;
            }
            total_word_length++;
        } 
        else {
            if (in_word) {
                in_word = false;
            }
            if (ispunct(text[i])) {
                if (last_punctuation_position != -1) {
                    total_punctuation_distance += (i - last_punctuation_position - 1);
                    punctuation_count++;
                }
                last_punctuation_position = i;
            }
        }
    }
    double average_word_length = static_cast<double>(total_word_length) / word_count;
    double average_punctuation_distance = punctuation_count > 0 ? static_cast<double>(total_punctuation_distance) / punctuation_count : 0;

    cout << "Avg world length: " << average_word_length << endl;
    cout << "Avg between marks: " << average_punctuation_distance << endl;

    return 0;
}