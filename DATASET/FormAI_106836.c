//FormAI DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char text[MAX];
char summary[MAX];

char* getText() {
    printf("Enter the text you want to summarize (max 1000 characters):\n");
    fgets(text, MAX, stdin);
    return text;
}

int getSummary() {
    int sentenceCount = 0;
    char *sentence = strtok(text, ".\n");
    while (sentence != NULL) {
        sentenceCount++;
        if (strstr(sentence, "important") != NULL ||
            strstr(sentence, "matters") != NULL ||
            strstr(sentence, "significant") != NULL) {
            strcat(summary, sentence);
            strcat(summary, ". ");
        }
        sentence = strtok(NULL, ".\n");
    }
    return sentenceCount;
}

void printSummary(int sentenceCount) {
    if (strlen(summary) > 0) {
        printf("\nSUMMARY\n");
        printf("------\n");
        printf("%s\n", summary);
        printf("------\n");
    } else {
        printf("Sorry, no important sentences found.\n");
    }
    printf("\nOriginal text had %d sentences.\n", sentenceCount);
    printf("Summary has %ld characters.\n", strlen(summary));
}

int main() {
    printf("Welcome to Text Summarizer!\n");
    char *text = getText();
    int sentenceCount = getSummary();
    printSummary(sentenceCount);
    return 0;
}