//FormAI DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

char *summarize(char *input, int max_words) {
    char *summary = malloc(sizeof(char)*MAX_SUMMARY_LENGTH);
    summary[0] = '\0';

    char *token = strtok(input, " ");
    int word_count = 0;

    while (token != NULL && word_count < max_words) {
        strcat(summary, token);
        strcat(summary, " ");
        token = strtok(NULL, " ");
        word_count++;
    }

    strcat(summary, "...");
    return summary;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int max_words;

    printf("Enter text to summarize: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    printf("Enter maximum number of words in summary: ");
    scanf("%d", &max_words);

    char *summary = summarize(input, max_words);
    printf("Summary: %s\n", summary);

    free(summary);
    return 0;
}