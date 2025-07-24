//FormAI DATASET v1.0 Category: Text Summarizer ; Style: standalone
// A simple example program for text summarization in C language.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100 // maximum number of sentences in the input text
#define MAX_LENGTH 1000 // maximum length of a sentence in the input text
#define MAX_SUMMARY_LENGTH 500 // maximum length of the summary

// Function to calculate the frequency of each word in the input text
void calculateWordFrequencies(char *text, int *frequencies, char **words, int *numWords) {
    // Tokenize the text into words
    char *tok;
    tok = strtok(text, " .,!?:;");
    while (tok != NULL) {
        int found = 0;
        // Check if the word is already present in the array of words
        for (int i = 0; i < *numWords; i++) {
            if (strcmp(tok, words[i]) == 0) {
                frequencies[i]++;
                found = 1;
                break;
            }
        }
        // If the word is not present in the array of words, add it
        if (!found) {
            strcpy(words[*numWords], tok);
            frequencies[*numWords] = 1;
            (*numWords)++;
        }
        tok = strtok(NULL, " .,!?:;");
    }
}

// Function to calculate the score of each sentence in the input text
void calculateSentenceScores(char *text, int *frequencies, char **words, int numWords, int *scores) {
    // Tokenize the text into sentences
    char *tok;
    tok = strtok(text, ".?!");
    int sentenceCount = 0;
    while (tok != NULL) {
        // Tokenize each sentence into words
        int sentenceScore = 0;
        char *wordTok;
        wordTok = strtok(tok, " .,!?:;");
        while (wordTok != NULL) {
            // Check if the word is present in the array of words
            for (int i = 0; i < numWords; i++) {
                if (strcmp(wordTok, words[i]) == 0) {
                    sentenceScore += frequencies[i];
                }
            }
            wordTok = strtok(NULL, " .,!?:;");
        }
        scores[sentenceCount] = sentenceScore;
        sentenceCount++;
        tok = strtok(NULL, ".?!");
    }
}

// Function to select the sentences with the highest scores for the summary
void selectSentences(char *text, int *frequencies, char **words, int numWords, int *scores, char *summary) {
    // Tokenize the text into sentences
    char *tok;
    tok = strtok(text, ".?!");
    int sentenceCount = 0;
    while (tok != NULL) {
        // Check if the sentence has a score greater than the threshold
        if (scores[sentenceCount] > 0) {
            strcat(summary, tok);
            strcat(summary, ". ");
        }
        sentenceCount++;
        tok = strtok(NULL, ".?!");
    }
}

int main() {
    // Read the input text
    char inputText[MAX_SENTENCES * MAX_LENGTH];
    printf("Enter the text to be summarized:\n");
    fgets(inputText, sizeof(inputText), stdin);
    inputText[strcspn(inputText, "\n")] = '\0';

    // Calculate the frequency of each word in the input text
    int wordFrequencies[MAX_SENTENCES];
    char *words[MAX_SENTENCES];
    for (int i = 0; i < MAX_SENTENCES; i++) {
        words[i] = malloc(MAX_LENGTH * sizeof(char));
    }
    int numWords = 0;
    calculateWordFrequencies(inputText, wordFrequencies, words, &numWords);

    // Calculate the score of each sentence in the input text
    int sentenceScores[MAX_SENTENCES];
    calculateSentenceScores(inputText, wordFrequencies, words, numWords, sentenceScores);

    // Select the sentences with the highest scores for the summary
    char summary[MAX_SUMMARY_LENGTH];
    selectSentences(inputText, wordFrequencies, words, numWords, sentenceScores, summary);

    // Print the summary
    printf("Summary:\n%s\n", summary);

    // Free memory
    for (int i = 0; i < MAX_SENTENCES; i++) {
        free(words[i]);
    }

    return 0;
}