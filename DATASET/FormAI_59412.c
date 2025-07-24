//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINPUT 10000

int countWords(char *input) {
    int wordCount = 0;
    int len = strlen(input);
    int i = 0;

    // Skip over any spaces at the beginning of the input
    while (i < len && input[i] == ' ') {
        i++;
    }

    // Count the words
    while (i < len && input[i] != '\n') {
        // Treat double spaces as one word separator
        if (i > 0 && input[i] == ' ' && input[i-1] != ' ') {
            wordCount++;
        }
        i++;
    }

    // Add one for the last word
    if (i > 0 && input[i-1] != ' ' && input[i-1] != '\n') {
        wordCount++;
    }

    return wordCount;
}

void printResults(int wordCount) {
    printf("Number of words: %d\n", wordCount);
    if (wordCount < 10) {
        printf("Text is very short.\n");
    } else if (wordCount < 20) {
        printf("Text is short.\n");
    } else if (wordCount < 30) {
        printf("Text is medium length.\n");
    } else if (wordCount < 40) {
        printf("Text is getting long.\n");
    } else {
        printf("Text is very long.\n");
    }
}

int main() {
    char input[MAXINPUT];
    printf("Enter some text:\n");
    if (fgets(input, MAXINPUT, stdin) == NULL) {
        printf("Input error.");
        return 1;
    }

    int wordCount = countWords(input);
    printResults(wordCount);

    return 0;
}