//FormAI DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_LENGTH = 1000;

char* summarize(char string[]) {
    char *result = malloc(MAX_LENGTH * sizeof(char));
    strcpy(result, "");

    char *token = strtok(string, " ");
    int wordCount = 0;

    while (token != NULL) {
        strcat(result, token);
        strcat(result, " ");
        wordCount++;

        if (wordCount == 10) {
            break;
        }

        token = strtok(NULL, " ");
    }

    return result;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter your text: ");
    fgets(input, MAX_LENGTH, stdin);
    char *summary = summarize(input);

    printf("\nSummary: \n%s", summary);

    free(summary);
    return 0;
}