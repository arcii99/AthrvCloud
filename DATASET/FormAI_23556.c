//FormAI DATASET v1.0 Category: Text Summarizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100


int get_word_count(char *string) {
    int count = 1;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ')
            count++;
    }

    return count;
}


int main() {
    char input_string[MAX_STRING_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];

    printf("Enter a paragraph to summarize: ");
    fgets(input_string, sizeof(input_string), stdin);

    int word_count = get_word_count(input_string);
    int summary_length = word_count / 5;

    if (summary_length > MAX_SUMMARY_LENGTH) {
        summary_length = MAX_SUMMARY_LENGTH;
    }

    char *token = strtok(input_string, " ");
    int count = 0;

    while (token != NULL && count < summary_length) {
        strcat(summary, token);
        strcat(summary, " ");
        token = strtok(NULL, " ");
        count++;
    }

    summary[strlen(summary) - 1] = '\0';
    printf("The summary of the paragraph is: %s\n", summary);

    return 0;
}