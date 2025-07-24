//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

int main() {
    char current_word[MAX_WORD_LEN];
    int word_count = 0, i, j;
    int word_lengths[MAX_WORD_LEN] = {0};

    // Read in user input
    printf("Enter some text: ");
    while (scanf("%s", current_word) > 0) {
        word_count++;
        int word_len = strlen(current_word);

        // Increment the count for the current word length
        if (word_len < MAX_WORD_LEN) {
            word_lengths[word_len]++;
        }

        // Convert word to lowercase
        for (i = 0; i < word_len; i++) {
            current_word[i] = tolower(current_word[i]);
        }
    }

    // Print out frequency table
    printf("\nFrequency Table:\n");
    printf("-----------------\n");
    printf("Word Length | Frequency\n");
    printf("-----------------------\n");
    for (i = 1; i < MAX_WORD_LEN; i++) {
        // Print the length of the word
        printf("%-11d | ", i);

        // Print the frequency count
        for (j = 0; j < word_lengths[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\nTotal Words: %d\n", word_count);

    return 0;
}