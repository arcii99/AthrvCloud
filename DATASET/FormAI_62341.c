//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_CHARACTERS 1000

int numberOfSentences;
char sentences[MAX_SENTENCES][MAX_CHARACTERS], summary[MAX_CHARACTERS];
int sentenceScores[MAX_SENTENCES];

void summarizeText() {
    int i,j;

    // Splitting the text into individual sentences
    char *tokens = strtok(sentences, ".");
    while (tokens != NULL) {
        strcpy(sentences[numberOfSentences++], tokens);
        tokens = strtok(NULL, ".");
    }

    // Count the frequency of occurrence of a word in each sentence
    for (i=0; i<numberOfSentences; i++) {
        sentenceScores[i] = 0;
        for (j=0; j<strlen(sentences[i]); j++) {
            if (sentences[i][j] == ' ') {
                sentenceScores[i]++;
            }
        }
    }

    // Select top 25% highest scoring sentences to form summary
    int summaryLength = numberOfSentences/4;
    int summaryIndex = 0;
    for (i=0; i<numberOfSentences && summaryIndex<summaryLength; i++) {
        if (sentenceScores[i] >= (int)(0.75 * (float)numberOfSentences)) {
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
            summaryIndex++;
        }
    }
}

int main() {
    char text[MAX_CHARACTERS];
    printf("Enter text to summarize:\n");
    fgets(text, MAX_CHARACTERS, stdin);

    if (strlen(text) == 0) {
        printf("Error: no input provided\n");
        return -1;
    }

    // Removing new line character from input text
    if (text[strlen(text)-1] == '\n') {
        text[strlen(text)-1] = '\0';
    }

    strcpy(sentences[numberOfSentences++], text);
    summarizeText();

    printf("Summary:\n%s\n", summary);

    return 0;
}