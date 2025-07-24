//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

int main() {
    char input_text[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int word_count[MAX_NUM_WORDS] = {0};
    int num_distinct_words = 0;
    int total_words = 0;

    printf("Enter text to count word frequencies (Enter '.' to stop):\n");
    char input_word[MAX_WORD_LENGTH];
    scanf("%49s", &input_word);

    while (strcmp(input_word, ".") != 0 && num_distinct_words <= MAX_NUM_WORDS) {
        total_words++;

        // Convert input word to lowercase
        int i;
        for (i=0; input_word[i]; i++) {
            input_word[i] = tolower(input_word[i]);
        }

        // Add input word to list of distinct words
        int j;
        for (j=0; j<num_distinct_words; j++) {
            if (strcmp(input_word, input_text[j]) == 0) {
                word_count[j]++;
                break;
            }
        }
        if (j == num_distinct_words) {
            strcpy(input_text[num_distinct_words], input_word);
            word_count[num_distinct_words]++;
            num_distinct_words++;
        }

        scanf("%49s", &input_word);
    }

    printf("\nTotal words: %d\n", total_words);
    printf("Distinct words: %d\n\n", num_distinct_words);

    printf("Word frequencies:\n");
    int k;
    for (k=0; k<num_distinct_words; k++) {
        printf("%s: %d\n", input_text[k], word_count[k]);
    }

    return EXIT_SUCCESS;
}