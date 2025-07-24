//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 1000
#define MAX_SUMMARY 100

int main() {
    char input[MAX_CHARS];
    char summary[MAX_SUMMARY];

    printf("Enter text to summarize (maximum 1000 characters):\n");
    fgets(input, MAX_CHARS, stdin);

    printf("Enter summary length (maximum 100 characters):\n");
    int summaryLength;
    scanf("%d", &summaryLength);

    if (summaryLength > MAX_SUMMARY) {
        printf("Error: summary length exceeds maximum.\n");
        return 1;
    }

    // remove new line character from input
    input[strcspn(input, "\n")] = '\0';

    // tokenize input into words
    char* word = strtok(input, " ");
    int numWords = 0;
    while (word != NULL) {
        numWords++;
        word = strtok(NULL, " ");
    }

    // ensure summary length is valid
    if (summaryLength < numWords) {
        printf("Error: summary length is shorter than input text.\n");
        return 1;
    }

    // get first n words of input text
    strncpy(summary, input, MAX_SUMMARY);
    for (int i = summaryLength+1; i < MAX_SUMMARY; i++) {
        summary[i] = '\0';
    }

    printf("Summary:\n%s\n", summary);

    return 0;
}