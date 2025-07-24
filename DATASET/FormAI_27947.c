//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
    char c, word[MAX_WORD_LENGTH] = {0};
    int word_count = 0, letter_count = 0;

    printf("Enter text: ");

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (letter_count < MAX_WORD_LENGTH) {
                word[letter_count++] = c;
            }
        } else {
            if (letter_count > 0) {
                word_count++;
                letter_count = 0;
                printf("%s\n", word);
                for (int i = 0; i < MAX_WORD_LENGTH; i++) {
                    word[i] = 0;
                }
            }
        }
    }

    printf("Word count: %d\n", word_count);

    return 0;
}