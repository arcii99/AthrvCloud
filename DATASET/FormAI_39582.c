//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_SUMMARY_SIZE 256

char *summarize(char *input);

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE], *summary;

    printf("Enter the text to summarize:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    summary = summarize(input);

    printf("Summary:\n%s\n", summary);

    free(summary);

    return 0;
}

char *summarize(char *input) {
    char *summary = (char *)malloc(MAX_SUMMARY_SIZE * sizeof(char));
    char *token, *prevtoken, *saveptr;
    int sumlen = 0;

    token = strtok_r(input, " \n", &saveptr);
    prevtoken = "";

    while (token != NULL) {
        if (sumlen + strlen(token) + 1 > MAX_SUMMARY_SIZE) break;
        if (strcmp(token, prevtoken) != 0) {
            strcat(summary, token);
            strcat(summary, " ");
            sumlen += strlen(token) + 1;
        }

        prevtoken = token;
        token = strtok_r(NULL, " \n", &saveptr);
    }

    summary[strlen(summary)-1] = '\0'; // Remove final space

    return summary;
}