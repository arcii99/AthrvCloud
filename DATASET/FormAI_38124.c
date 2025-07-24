//FormAI DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SUMMARY_CHAR 100
#define MAX_TEXT_CHAR 1000

void summarize(char *summary, char *text, int start, int count);

int main() {
    char text[MAX_TEXT_CHAR];
    char summary[MAX_SUMMARY_CHAR];

    printf("Enter text to summarize: ");
    fgets(text, MAX_TEXT_CHAR, stdin);

    summarize(summary, text, 0, 0);

    printf("\nSummary: %s\n", summary);

    return 0;
}

void summarize(char *summary, char *text, int start, int count) {
    char word[MAX_TEXT_CHAR];
    int i = start, j = 0;

    if (count >= MAX_SUMMARY_CHAR) {
        // We've reached the maximum summary length, so we're done.
        summary[count] = '\0';
        return;
    }

    while (text[i] != '\0') {
        if (count >= MAX_SUMMARY_CHAR) {
            // We've reached the maximum summary length, so we're done.
            summary[count] = '\0';
            return;
        }

        if (isspace(text[i]) || text[i] == '\n' || text[i] == '\r' || text[i] == '\t' || text[i] == '\0') {
            word[j] = '\0';
            j = 0;

            if (strlen(word) > 0 && strlen(word) < 5) {
                // Skip short words (less than 5 characters).
                i++;
            } else if (strlen(word) > 0) {
                // Add the word to the summary and continue.
                strcat(summary, word);
                strcat(summary, " ");
                count += strlen(word) + 1;
                i++;
            } else {
                // Skip empty space.
                i++;
            }
        } else {
            word[j] = tolower(text[i]);
            j++;
            i++;
        }
    }

    summarize(summary, text, start + 1, count);
}