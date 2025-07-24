//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int main()
{
    int c, i;
    int word_count[MAX_WORD_LENGTH + 1]; // array to hold word count for each word length

    for (i = 0; i <= MAX_WORD_LENGTH; ++i) {
        word_count[i] = 0;
    }

    printf("Welcome to the C Word Frequency Counter!\nEnter some text (press CTRL + D to exit):\n\n");

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            int word_length = 0;
            char word[MAX_WORD_LENGTH + 1];

            while (isalpha(c) && word_length < MAX_WORD_LENGTH) {
                word[word_length++] = tolower(c);
                c = getchar();
            }

            word[word_length] = '\0';

            ++word_count[word_length];
        }
    }

    printf("\nWord frequency by length:\n\n");

    for (i = 1; i <= MAX_WORD_LENGTH; ++i) {
        if (word_count[i] == 0) {
            continue;
        }

        printf("%2d: %d\n", i, word_count[i]);
    }

    return 0;
}