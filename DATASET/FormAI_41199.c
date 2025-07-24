//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS   1000

int main(int argc, char *argv[]) {
    int i, j, k, num_words;
    int counts[MAX_NUM_WORDS];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    char input_str[MAX_WORD_LENGTH];
    char *tokens[MAX_NUM_WORDS];
    char *ptr;

    printf("Enter a sentence: ");
    fgets(input_str, MAX_WORD_LENGTH, stdin);

    num_words = 0;
    ptr = strtok(input_str, " ");
    while (ptr != NULL && num_words < MAX_NUM_WORDS) {
        strncpy(words[num_words], ptr, MAX_WORD_LENGTH);
        counts[num_words] = 1;
        tokens[num_words] = words[num_words];
        num_words++;
        ptr = strtok(NULL, " ");
    }

    for (i = 0; i < num_words-1; i++) {
        for (j = i+1; j < num_words; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                counts[i]++;
                counts[j] = 0;
            }
        }
    }

    printf("Word frequency counts:\n");
    for (i = 0; i < num_words; i++) {
        if (counts[i] > 0) {
            printf("%s: %d\n", words[i], counts[i]);
        }
    }

    return 0;
}