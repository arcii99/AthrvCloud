//FormAI DATASET v1.0 Category: Text Summarizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 10000
#define MAX_SUMMARY_LEN 500

int main() {
    printf("Welcome to the Grateful Text Summarizer!\n");
    printf("Please enter the text you would like to summarize:\n");

    char input[MAX_INPUT_LEN];
    fgets(input, MAX_INPUT_LEN, stdin);

    // Remove trailing newline character from user input
    input[strcspn(input, "\n")] = 0;

    printf("\nThank you for your input! Here is your summarized text:\n");

    char* token = strtok(input, " ");
    int summary_length = 0;
    char summary[MAX_SUMMARY_LEN] = "";

    while (token != NULL) {
        int token_length = strlen(token);

        if (summary_length + token_length <= MAX_SUMMARY_LEN) {
            strcat(summary, token);
            strcat(summary, " ");
            summary_length += token_length + 1;
        } else {
            break;
        }

        token = strtok(NULL, " ");
    }

    printf("%s...\n", summary);
    printf("\nThank you for using the Grateful Text Summarizer!");

    return 0;
}