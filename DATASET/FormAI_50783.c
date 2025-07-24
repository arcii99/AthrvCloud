//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_SUMMARY_LENGTH 50

void summarize(char *text, char *summary);

int main() {
    // Romeo's text
    char romeosText[MAX_LINE_LENGTH] = "But soft! What light through yonder window breaks? It is the east, and Juliet is the sun.";
    // Juliet's text
    char julietsText[MAX_LINE_LENGTH] = "O Romeo, Romeo! Wherefore art thou Romeo?";
    // Final summary
    char summary[MAX_SUMMARY_LENGTH];

    // Print Romeo's text
    printf("Romeo: %s\n", romeosText);

    // Summarize Romeo's text
    summarize(romeosText, summary);

    // Print Romeo's summary
    printf("Romeo's Summary: %s\n", summary);

    // Print Juliet's text
    printf("Juliet: %s\n", julietsText);

    // Summarize Juliet's text
    summarize(julietsText, summary);

    // Print Juliet's summary
    printf("Juliet's Summary: %s\n", summary);

    return 0;
}

void summarize(char *text, char *summary) {
    // Split the text into words
    char *words[100];
    char *word = strtok(text, " ");
    int numWords = 0;
    while (word != NULL) {
        words[numWords] = word;
        numWords++;
        word = strtok(NULL, " ");
    }

    // Choose the first numWords/2 words as the summary
    int numSummaryWords = numWords / 2;
    strcpy(summary, words[0]);
    for (int i = 1; i < numSummaryWords; i++) {
        strcat(summary, " ");
        strcat(summary, words[i]);
    }
    strcat(summary, "...");
}