//FormAI DATASET v1.0 Category: Text Summarizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SENTENCES 1000
#define MAX_SENTENCE_LENGTH 200

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int score;
} Sentence;

int numberOfOccurrences(char *substring, char *string) {
    int count = 0;
    char *ptr = string;
    while ((ptr = strstr(ptr, substring))) {
        count++;
        ptr++;
    }

    return count;
}

bool contains(char **keywords, int numKeywords, char *sentence) {
    for (int i = 0; i < numKeywords; i++) {
        if (strstr(sentence, keywords[i])) {
            return true;
        }
    }

    return false;
}

int main() {

    char originalText[MAX_SENTENCES * MAX_SENTENCE_LENGTH];
    char keywords[10][20];
    Sentence sentences[MAX_SENTENCES];

    printf("Enter text to be summarized:\n");
    fgets(originalText, sizeof(originalText), stdin);

    printf("\nEnter keywords to summarize text separated by commas:\n");
    char *keyword = strtok(fgets(keywords, sizeof(keywords), stdin), ",");

    int keywordCount = 0;
    while (keyword != NULL) {
        strcpy(keywords[keywordCount], keyword);
        keywordCount++;
        keyword = strtok(NULL, ",");
    }

    int sentenceCount = 0;
    char *delim = ".\n";
    char *sentence = strtok(originalText, delim);
    while (sentence != NULL) {
        strcpy(sentences[sentenceCount].sentence, sentence);
        sentenceCount++;
        sentence = strtok(NULL, delim);
    }

    int i, j, k, numOccurrences;
    for (i = 0; i < sentenceCount; i++) {
        numOccurrences = numberOfOccurrences(keywords[0], sentences[i].sentence);
        for (j = 1; j < keywordCount; j++) {
            numOccurrences += numberOfOccurrences(keywords[j], sentences[i].sentence);
        }
        sentences[i].score = numOccurrences;
    }

    for (i = 0; i < sentenceCount; i++) {
        for (j = i + 1; j < sentenceCount; j++) {
            if (sentences[i].score < sentences[j].score) {
                Sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    printf("\nSummary:\n");
    for (i = 0; i < sentenceCount / 2; i++) {
        printf("%s. ", sentences[i].sentence);
    }

    return 0;
}