//FormAI DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 10000
#define MAX_SUMMARY_LEN 1000

void summarize(char *text, char *summary) {
    char *delim = ".!?\n";
    char *sentence = strtok(text, delim);
    int count = 0;
    while (sentence != NULL) {
        if (count == MAX_SUMMARY_LEN) {
            break;
        }
        strcat(summary, sentence);
        strcat(summary, ". ");
        sentence = strtok(NULL, delim);
        count++;
    }
}

int main(void) {
    char text[MAX_TEXT_LEN];
    char summary[MAX_SUMMARY_LEN] = "";
    printf("Enter the text to summarize:\n");
    fgets(text, MAX_TEXT_LEN, stdin);
    summarize(text, summary);
    printf("Summary:\n%s\n", summary);
    return 0;
}