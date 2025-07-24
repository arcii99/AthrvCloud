//FormAI DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 10
#define MAX_SUMMARY_LENGTH 200

void readInput(char *input) {
    printf("Enter the text you want to summarize: ");
    fgets(input, MAX_SUMMARY_LENGTH, stdin);
}

int countWords(char *sentence) {
    int count = 0;
    char *word = strtok(sentence, " ");
    while (word) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

void getTopSentences(int *sentenceScores, int *topSentences) {
    int maxScore, topSentence;

    for (int i = 0; i < MAX_SENTENCES; i++) {
        maxScore = -1;
        topSentence = -1;
        for (int j = 0; j < MAX_SENTENCES; j++) {
            if (sentenceScores[j] > maxScore) {
                maxScore = sentenceScores[j];
                topSentence = j;
            }
        }
        topSentences[i] = topSentence;
        sentenceScores[topSentence] = -1;
    }
}

void printSummary(char *input, int *topSentences) {
    char summary[MAX_SUMMARY_LENGTH];
    int summaryLength = 0;
    for (int i = 0; i < MAX_SENTENCES; i++) {
        int sentenceLength = strlen(&input[topSentences[i]]);
        if (summaryLength + sentenceLength > MAX_SUMMARY_LENGTH) {
            break;
        }
        strcat(summary, &input[topSentences[i]]);
        summaryLength += sentenceLength;
    }
    printf("\nSummary: %s\n", summary);
}

int main() {
    char input[MAX_SUMMARY_LENGTH], *sentence;
    int sentenceLengths[MAX_SENTENCES], sentenceScores[MAX_SENTENCES] = {0}, wordCount, topSentences[MAX_SENTENCES];

    readInput(input);

    // Split input into sentences and store the lengths
    sentence = strtok(input, ".\n");
    for (int i = 0; i < MAX_SENTENCES && sentence; i++) {
        sentenceLengths[i] = strlen(sentence);
        sentence = strtok(NULL, ".\n");
    }

    // Calculate scores for each sentence based on word count
    sentence = strtok(input, ".\n");
    for (int i = 0; i < MAX_SENTENCES && sentence; i++) {
        wordCount = countWords(sentence);
        sentenceScores[i] = wordCount;
        sentence = strtok(NULL, ".\n");
    }

    // Find top sentences and generate summary
    getTopSentences(sentenceScores, topSentences);
    printSummary(input, topSentences);

    return 0;
}