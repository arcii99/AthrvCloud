//FormAI DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 200

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    int i, j;

    printf("Enter text to be summarized:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove new line character if exists
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Tokenize input
    char *token;
    char *summary = (char *) malloc(MAX_OUTPUT_SIZE * sizeof(char));
    token = strtok(input, " ");
    int words = 0;

    // Loop through tokens and add to summary until max words reached
    while (token != NULL && words < 10) {
        strcat(summary, token);
        strcat(summary, " ");
        words++;
        token = strtok(NULL, " ");
    }

    // Add ellipsis if more than 10 words
    if (words >= 10) {
        strcat(summary, "...");
    }

    // Copy summary to output and print
    strcpy(output, summary);

    printf("\nSummary:\n%s\n", output);

    return 0;
}