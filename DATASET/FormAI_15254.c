//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 10000
#define MAX_SENTENCES 500
#define MAX_SENTENCE_LENGTH 200

int main() {
    char text[MAX_CHARACTERS];
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentenceCount = 0;
    int i, j;

    printf("Enter the text to be summarized:\n");
    fgets(text, MAX_CHARACTERS, stdin);

    for (i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentenceCount++;
        }
    }

    if (sentenceCount > MAX_SENTENCES) {
        printf("Error: Text too long. Maximum sentence count is %d.", MAX_SENTENCES);
        return 1;
    }

    int sentenceIndex = 0;
    char* token = strtok(text, ".?!");

    while(token != NULL) {
        strcpy(sentences[sentenceIndex++], token);
        token = strtok(NULL, ".?!");
    }

    int scores[sentenceCount];
    memset(scores, 0, sizeof(scores));

    for (i = 0; i < sentenceCount; i++) {
        for (j = 0; j < strlen(sentences[i]); j++) {
            if (isalnum(sentences[i][j])) {
                scores[i]++;
            }
        }
    }

    int summaryLength = sentenceCount / 2;
    printf("Summary:\n");

    for (i = 0; i < summaryLength; i++) {
        int max = -1;
        int maxIndex = 0;

        for (j = 0; j < sentenceCount; j++) {
            if (scores[j] > max) {
                max = scores[j];
                maxIndex = j;
            }
        }

        printf("%s. ", sentences[maxIndex]);
        scores[maxIndex] = 0;
    }

    return 0;
}