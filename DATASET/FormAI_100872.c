//FormAI DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

void to_lower_case(char *word);
void print_word_counts(int *counts);
void reset_counts(int *counts);

int main() {
    char c, word[MAX_WORD_LEN];
    int in_word = 0, word_len = 0, counts[MAX_WORD_LEN + 1] = {0};

    printf("Enter some text and I will count the word lengths: \n");

    while ((c = getchar()) != EOF) {
        if (isalnum(c)) {
            if (!in_word) {
                in_word = 1;
            }
            word[word_len++] = tolower(c);
        } else {
            if (in_word) {
                in_word = 0;
                word[word_len] = '\0';
                to_lower_case(word);
                counts[word_len]++;
                word_len = 0;
            }
        }
    }

    print_word_counts(counts);
    reset_counts(counts);

    return 0;
}

void to_lower_case(char *word) {
    while (*word) {
        *word = tolower(*word);
        word++;
    }
}

void print_word_counts(int *counts) {
    printf("Word counts: \n");

    for (int i = 1; i < MAX_WORD_LEN + 1; i++) {
        if (counts[i] > 0) {
            printf("%d: %d\n", i, counts[i]);
        }
    }

    printf("\n");
}

void reset_counts(int *counts) {
    for (int i = 1; i < MAX_WORD_LEN + 1; i++) {
        counts[i] = 0;
    }
}