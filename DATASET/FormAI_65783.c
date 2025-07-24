//FormAI DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

const int MAX_WORD_LENGTH = 100;

int main() {
    char c, word[MAX_WORD_LENGTH];
    bool in_word = false;
    int word_count = 0, letter_count = 0;

    printf("Enter some text: ");

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (!in_word) {
                in_word = true;
            }
            if (letter_count < MAX_WORD_LENGTH) {
                word[letter_count] = c;
            }
            letter_count++;
        } else {
            if (in_word) {
                in_word = false;
                word[letter_count] = '\0';
                letter_count = 0;
                word_count++;
            }
        }
    }

    if (in_word) {
        word[letter_count] = '\0';
        word_count++;
    }

    printf("\nWord count: %d\n", word_count);

    return 0;
}