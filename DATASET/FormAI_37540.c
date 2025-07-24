//FormAI DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SENTENCE_COUNT 50
#define MAX_SENTENCE_LENGTH 1000

/* Function to remove punctuations from a string */
void removePunctuations(char* str) {
    int i = 0, j = 0;

    while (str[i]) {
        if (!ispunct((unsigned char)str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

/* Function to find the average sentence length */
int findAvgSentenceLength(char* input) {
    int sentenceCount = 0, totalWords = 0, sentenceLength = 0;
    char* tmpInput = strdup(input);
    char* token = strtok(tmpInput, ".?!\n");

    while (token) {
        char* tmpToken = strdup(token);
        removePunctuations(tmpToken);
        int wordCount = 0;
        char* word = strtok(tmpToken, " ");

        while (word) {
            wordCount++;
            word = strtok(NULL, " ");
        }

        totalWords += wordCount;
        sentenceLength += strlen(token);
        sentenceCount++;
        free(tmpToken);
        token = strtok(NULL, ".?!\n");
    }

    if (sentenceCount > 0) {
        free(tmpInput);
        return (int)((float)totalWords / (float)sentenceCount);
    } else {
        free(tmpInput);
        return 0;
    }
}

/* Function to summarize the input text */
void summarizeText(char* input) {
    int avgSentenceLength = findAvgSentenceLength(input);
    int sentenceCount = 0;
    char sentences[MAX_SENTENCE_COUNT][MAX_SENTENCE_LENGTH] = { "" };
    char* tmpInput = strdup(input);
    char* token = strtok(tmpInput, ".?!\n");

    while (token) {
        if (strlen(token) > 0) {
            strcpy(sentences[sentenceCount], token);
            sentenceCount++;
        }
        token = strtok(NULL, ".?!\n");
    }

    for (int i = 0; i < sentenceCount; i++) {
        char* sentence = sentences[i];
        char* tmpSentence = strdup(sentence);
        removePunctuations(tmpSentence);
        int wordCount = 0;
        char* word = strtok(tmpSentence, " ");

        while (word) {
            wordCount++;
            word = strtok(NULL, " ");
        }

        if (wordCount > avgSentenceLength) {
            printf("%s\n", sentence);
        }

        free(tmpSentence);
    }

    free(tmpInput);
}

/* Main function */
int main() {
    char input[MAX_INPUT_SIZE] = { 0 };

    printf("Enter a paragraph of text:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    printf("\n--- Summarized Text ---\n\n");
    summarizeText(input);

    return 0;
}