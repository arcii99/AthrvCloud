//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT 10000
#define MAX_WORD_LENGTH 50

int main() {
    char input[MAX_INPUT];
    printf("Enter text: ");
    fgets(input, MAX_INPUT, stdin);

    // Convert text to lower case
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Split input into words
    char words[MAX_INPUT][MAX_WORD_LENGTH];  // 2D array to store words
    int word_count[MAX_INPUT] = {0};         // Array to store frequency of each word
    int num_words = 0;
    char *word;
    word = strtok(input, " ");
    while (word != NULL) {
        strcpy(words[num_words], word);
        word_count[num_words]++;
        num_words++;
        word = strtok(NULL, " ");
    }

    // Count frequency of each word
    for (int i = 0; i < num_words; i++) {
        for (int j = i+1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_count[i]++;
                word_count[j] = -1; // Mark as counted
            }
        }
    }

    // Print results
    printf("\nWord frequency:\n");
    for (int i = 0; i < num_words; i++) {
        if (word_count[i] != -1) {
            printf("%s: %d\n", words[i], word_count[i]);
        }
    }

    return 0;
}