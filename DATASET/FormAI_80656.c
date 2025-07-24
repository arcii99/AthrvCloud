//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

int main() {
    char word[MAX_WORD_LEN];
    int word_count = 0;
    int i, j, c, is_word;

    int word_lengths[MAX_WORDS];
    int unique_lengths = 0;
    int word_length_counts[MAX_WORD_LEN];

    for (i = 0; i < MAX_WORDS; i++) {
        word_lengths[i] = 0;
    }

    for (i = 0; i < MAX_WORD_LEN; i++) {
        word_length_counts[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (isalnum(c)) {
            is_word = 1;

            if (isupper(c)) {
                c = tolower(c);
            }

            word[word_count++] = c;

            if (word_count >= MAX_WORD_LEN) {
                printf("Error: word too long\n");
                return 1;
            }
        } else {
            if (is_word) {
                word_lengths[unique_lengths++] = word_count;
                word_length_counts[word_count - 1]++;
            }

            word_count = 0;
            is_word = 0;
        }
    }

    if (word_count > 0) {
        word_lengths[unique_lengths++] = word_count;
        word_length_counts[word_count - 1]++;
    }

    printf("Word count: %d\n", unique_lengths);

    printf("Word length histogram:\n");
    for (i = 0; i < MAX_WORD_LEN; i++) {
        if (word_length_counts[i] > 0) {
            printf("%2d: ", i + 1);

            for (j = 0; j < word_length_counts[i]; j++) {
                printf("*");
            }

            printf("\n");
        }
    }

    return 0;
}