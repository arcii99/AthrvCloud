//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_WORDS];
    int count = 0;

    char input[1000];
    printf("Enter text (1000 characters max):\n");
    fgets(input, 1000, stdin);

    // Tokenize input into words
    char *token = strtok(input, " \n\t");
    while (token != NULL) {
        // Convert all characters to lowercase
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // Check if word is already in array
        int i;
        for (i = 0; i < count; i++) {
            if (strcmp(words[i], token) == 0) {
                frequency[i]++;
                break;
            }
        }

        // If word is not in array, add it and set frequency to 1
        if (i == count) {
            strcpy(words[count], token);
            frequency[count] = 1;
            count++;
        }

        // Get next token
        token = strtok(NULL, " \n\t");
    }

    // Sort word frequencies in descending order
    qsort(frequency, count, sizeof(int), compare);

    // Print word frequencies in descending order
    printf("Word Frequency:\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %d\n", words[i], frequency[i]);
    }

    return 0;
}