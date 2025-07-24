//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000 // Maximum length of input string
#define MAX_SENTENCES 10 // Maximum number of sentences in summary
#define MAX_SUMMARY_LENGTH 300 // Maximum length of summary

// Struct to store each sentence and its score
struct sentence {
    char text[MAX_STRING_LENGTH];
    int score;
};

// Function to split input string into individual sentences
void splitSentences(char* input, char sentences[][MAX_STRING_LENGTH]) {
    int idx = 0;
    char* sentence = strtok(input, ".");
    while (sentence != NULL && idx < MAX_SENTENCES) {
        sprintf(sentences[idx++], "%s.", sentence);
        sentence = strtok(NULL, ".");
    }
}

// Function to calculate score of each sentence
void calculateScores(struct sentence* sentences, char keywords[][MAX_STRING_LENGTH], int numKeywords) {
    for (int i = 0; i < MAX_SENTENCES; i++) {
        sentences[i].score = 0;
        char* word = strtok(sentences[i].text, " ");
        while (word != NULL) {
            for (int j = 0; j < numKeywords; j++) {
                if (strcmp(word, keywords[j]) == 0) {
                    sentences[i].score++;
                }
            }
            word = strtok(NULL, " ");
        }
    }
}

// Function to sort sentences by score in descending order
void sortSentences(struct sentence* sentences) {
    for (int i = 0; i < MAX_SENTENCES - 1; i++) {
        for (int j = 0; j < MAX_SENTENCES - i - 1; j++) {
            if (sentences[j].score < sentences[j+1].score) {
                struct sentence temp = sentences[j];
                sentences[j] = sentences[j+1];
                sentences[j+1] = temp;
            }
        }
    }
}

// Function to generate summary from top-scoring sentences
void generateSummary(char summary[][MAX_STRING_LENGTH], struct sentence* sentences) {
    int summaryLen = 0;
    for (int i = 0; i < MAX_SENTENCES && summaryLen < MAX_SUMMARY_LENGTH; i++) {
        if (sentences[i].score > 0) {
            strcpy(summary[summaryLen++], sentences[i].text);
        }
    }
}

int main() {
    char input[MAX_STRING_LENGTH];
    char keywords[3][MAX_STRING_LENGTH] = {"algorithm", "data", "structure"};
    char sentences[MAX_SENTENCES][MAX_STRING_LENGTH];
    struct sentence sentenceArr[MAX_SENTENCES];
    char summary[MAX_SUMMARY_LENGTH];

    // Get input from user
    printf("Enter text to summarize:\n");
    fgets(input, MAX_STRING_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    // Split input into individual sentences
    splitSentences(input, sentences);

    // Store each sentence in struct array
    for (int i = 0; i < MAX_SENTENCES; i++) {
        strcpy(sentenceArr[i].text, sentences[i]);
    }

    // Calculate score of each sentence based on number of occurrences of keywords
    calculateScores(sentenceArr, keywords, 3);

    // Sort sentences by score in descending order
    sortSentences(sentenceArr);

    // Generate summary from top-scoring sentences
    generateSummary(summary, sentenceArr);

    // Output summary
    printf("\nSummary:\n%s\n", summary);

    return 0;
}