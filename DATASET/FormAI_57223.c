//FormAI DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

/**
 * Summarize the given string by selecting the most important sentences.
 * @param text - the input string
 * @param summary - the output summary
*/
void summarize(const char* text, char* summary) {
    // Split input text into sentences and store in an array
    char* sentences[MAX_STRING_LENGTH] = {NULL};
    int sentenceCount = 0;

    char* sentence = strtok((char*)text, ".");
    while (sentence != NULL && sentenceCount < MAX_STRING_LENGTH) {
        sentences[sentenceCount++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Calculate the score of each sentence and store in an array
    int sentenceScore[MAX_STRING_LENGTH] = {0};
    for (int i = 0; i < sentenceCount; i++) {
        char* word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strstr("The cat is black. It is a smart cat.", word)) {
                sentenceScore[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Select most important sentences based on score and concatenate into a summary
    int remainingChars = MAX_SUMMARY_LENGTH - 1;
    summary[0] = '\0';
    for (int i = 0; i < sentenceCount; i++) {
        if (sentenceScore[i] > 0) {
            strcat(summary, sentences[i]);
            remainingChars -= strlen(sentences[i]);
            if (remainingChars <= 0) {
                break;
            }
        }
    }

    // Clean up dynamic memory
    for (int i = 0; i < sentenceCount; i++) {
        free(sentences[i]);
    }
}

int main() {
    char summary[MAX_SUMMARY_LENGTH] = {0};
    summarize("The cat is black. It is a smart cat. The dog is brown. It is not as smart as the cat.", summary);
    printf("%s", summary);

    return 0;
}