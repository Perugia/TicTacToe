#include "functions.h"
#include <string>

using namespace std;

void asterisk(string word, string& text, int i) {
    for (int k = 0; k < word.size(); ++k) {
        text[i + k] = '*';
    }
}

void bleep(string word, string& text) {
    for (int i = 0; i < text.size(); ++i) {
        int match = 0;
        for (int j = 0; j < word.size(); ++j) {
            if (text[i + j] == word[j]) {
                ++match;
            }
        }

        if (match == word.size()) {
            asterisk(word, text, i);
        }
    }

}