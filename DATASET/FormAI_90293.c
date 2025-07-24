//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

int main() {
    char inputLine[MAX_LINE_LENGTH];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int wordCount[MAX_NUM_WORDS];
    int i, j, k, n, maxCount, uniqueWords;

    printf("Enter the text to be processed:\n");

    // Read a line of input from the user
    fgets(inputLine, MAX_LINE_LENGTH, stdin);

    // Replace newline with null character
    inputLine[strcspn(inputLine, "\n")] = 0;

    // Split input line into words
    n = 0;
    char* token = strtok(inputLine, " ");
    while (token != NULL) {
        // Convert word to lowercase
        for (i = 0; i < strlen(token); i++) {
            if (token[i] >= 'A' && token[i] <= 'Z') {
                token[i] = token[i] - ('A' - 'a');
            }
        }

        // Check if word is already in words array
        for (i = 0; i < n; i++) {
            if (strcmp(token, words[i]) == 0) {
                wordCount[i]++;
                break;
            }
        }

        // If word is not already in words array, add it
        if (i == n) {
            strcpy(words[n], token);
            wordCount[n] = 1;
            n++;
        }

        // Get next token
        token = strtok(NULL, " ");
    }

    // Print out unique words and their counts
    printf("\nUnique Words:\n");
    uniqueWords = 0;
    maxCount = 0;
    for (i = 0; i < n; i++) {
        if (wordCount[i] > maxCount) {
            maxCount = wordCount[i];
        }

        printf("%s: %d\n", words[i], wordCount[i]);

        uniqueWords++;
    }

    // Print out statistical information
    printf("\nStatistics:\n");
    printf("Number of words: %d\n", n);
    printf("Number of unique words: %d\n", uniqueWords);
    printf("Most common word(s):\n");
    for (i = 0; i < n; i++) {
        if (wordCount[i] == maxCount) {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}