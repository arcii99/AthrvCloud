//FormAI DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SUMMARY_SIZE 100

char* summarizer(char* input) {
    char* summary = (char*)malloc(MAX_SUMMARY_SIZE * sizeof(char));
    if (summary == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    char* token = strtok(input, " ");
    int word_count = 0;

    while (token != NULL) {
        strcpy(summary, token);
        token = strtok(NULL, " ");

        if (token == NULL) {
            strcat(summary, ".");
        } else {
            strcat(summary, " ");
        }

        word_count++;

        if (word_count == 10) {
            break;
        }
    }

    return summary;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter text to summarize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    char* summary = summarizer(input);
    printf("Summary: %s\n", summary);

    free(summary);
    return 0;
}