//FormAI DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_SIZE 1000

// Function to print the summary of the text
void printSummary(char *text) {
    char *sentences[MAX_SENTENCES]; // array to store sentences
    int sentenceCount = 0;
    int index = 0;
    int sentenceStart = 0;
    int textLength = strlen(text);

    // Split text into sentences
    for (int i = 0; i < textLength; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            char *sentence = (char *) malloc((i - sentenceStart + 2) * sizeof(char));
            memcpy(sentence, &text[sentenceStart], i - sentenceStart + 1);
            sentence[i - sentenceStart + 1] = '\0';
            sentences[sentenceCount++] = sentence;
            sentenceStart = i + 1;
        }
    }

    // Calculate score for each sentence based on frequency of words
    int scores[MAX_SENTENCES];
    memset(scores, 0, sizeof(scores));
    for (int i = 0; i < sentenceCount; i++) {
        char *sentence = sentences[i];
        int len = strlen(sentence);
        char *lowerCaseSentence = (char *) malloc((len + 1) * sizeof(char));
        for (int j = 0; j < len; j++) {
            lowerCaseSentence[j] = tolower(sentence[j]);
        }

        char *word = strtok(lowerCaseSentence, " ");
        while (word != NULL) {
            for (int j = 0; j < sentenceCount; j++) {
                if (j == i) continue;
                
                if (strstr(sentences[j], word) != NULL) {
                    scores[i]++;
                }
            }
            word = strtok(NULL, " ");
        }

        free(lowerCaseSentence);
    }

    // Select top sentences with highest scores
    printf("\nSUMMARY:\n");
    for (int i = 0; i < 3; i++) {
        int maxScore = -1;
        int maxScoreIndex = -1;
        for (int j = 0; j < sentenceCount; j++) {
            if (scores[j] > maxScore) {
                maxScore = scores[j];
                maxScoreIndex = j;
            }
        }
        if (maxScoreIndex != -1) {
            printf("%s\n", sentences[maxScoreIndex]);
            scores[maxScoreIndex] = -1;
        }
    }

    // Free allocated memory
    for (int i = 0; i < sentenceCount; i++) {
        free(sentences[i]);
    }
}

int main() {
    char text[] = "This is a sample text. It contains several sentences. Each sentence should be scored based on frequency of words. The top scored sentences should be selected as summary.";
    printSummary(text);
    return 0;
}