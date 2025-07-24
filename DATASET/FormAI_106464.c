//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 50

char* text_summarizer(char* text, int summary_length);

int main() {
    char* text = (char*) malloc(MAX_TEXT_LENGTH * sizeof(char));
    printf("Welcome to the Curious Text Summarizer.\n");
    printf("Please input some text to summarize:\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    printf("\n");
    char* summary = text_summarizer(text, MAX_SUMMARY_LENGTH);
    printf("Here is your summary:\n%s\n", summary);
    free(text);
    free(summary);
    return 0;
}

char* text_summarizer(char* text, int summary_length) {
    int text_length = strlen(text);
    if (text_length <= summary_length) {
        char* summary = (char*) malloc((text_length + 1) * sizeof(char));
        strcpy(summary, text);
        return summary;
    }
    else {
        char* summary = (char*) malloc((summary_length + 1) * sizeof(char));
        strncpy(summary, text, summary_length-3);
        strcat(summary, "...");
        return summary;
    }
}