//FormAI DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000

void summarize(char *text) {
    // Initialize variables
    char sentences[MAX_SENTENCES][MAX_WORDS];
    char words[MAX_WORDS][MAX_WORDS];
    int sentenceCount = 0, wordCount = 0, i = 0, j = 0, k = 0;
    int sentenceLengths[MAX_SENTENCES] = {0};
    int wordLengths[MAX_WORDS] = {0};
    float sentenceScores[MAX_SENTENCES] = {0};

    // Split input text into individual sentences
    char *temp = strtok(text, ".!?");
    while(temp != NULL) {
        strcpy(sentences[sentenceCount], temp);
        sentenceLengths[sentenceCount] = strlen(temp);
        sentenceCount++;
        temp = strtok(NULL, ".!?");
    }

    // Split each sentence into individual words
    for(i = 0; i < sentenceCount; i++) {
        char *tempWord = strtok(sentences[i], " ");
        while(tempWord != NULL) {
            strcpy(words[wordCount], tempWord);
            wordLengths[wordCount] = strlen(tempWord);
            wordCount++;
            tempWord = strtok(NULL, " ");
        }
    }

    // Score each sentence based on word count and length
    for(i = 0; i < sentenceCount; i++) {
        for(j = 0; j < sentenceLengths[i]; j++) {
            if(sentences[i][j] == ' ') {
                sentenceScores[i] += 0.5;
            }
        }
        sentenceScores[i] += (float)(sentenceLengths[i]) / wordCount;
    }

    // Print the top 3 highest scoring sentences
    printf("Summary:\n");
    int summaryCount = (sentenceCount > 3) ? 3 : sentenceCount;
    for(i = 0; i < summaryCount; i++) {
        float maxScore = -1;
        int maxIndex = -1;
        for(j = 0; j < sentenceCount; j++) {
            if(sentenceScores[j] > maxScore) {
                maxScore = sentenceScores[j];
                maxIndex = j;
            }
        }
        printf("%s. ", sentences[maxIndex]);
        sentenceScores[maxIndex] = -1;
    }
}

int main() {
    char text[1000] = "The quick brown fox jumps over the lazy dog. "
                      "Lorem Ipsum is simply dummy text of the printing "
                      "and typesetting industry. It is a long established "
                      "fact that a reader will be distracted by the readable "
                      "content of a page when looking at its layout. "
                      "Many desktop publishing packages and web page editors "
                      "now use Lorem Ipsum as their default model text, "
                      "and a search for 'lorem ipsum' will uncover many web "
                      "sites still in their infancy. Various versions have "
                      "evolved over the years, sometimes by accident, sometimes "
                      "on purpose (injected humour and the like). "
                      "Contrary to popular belief, Lorem Ipsum is not simply "
                      "random text. It has roots in a piece of classical Latin "
                      "literature from 45 BC, making it over 2000 years old. "
                      "Richard McClintock, a Latin professor at Hampden-Sydney "
                      "College in Virginia, looked up one of the more obscure Latin "
                      "words, consectetur, from a Lorem Ipsum passage, and going through "
                      "suffering his proposed finding the undeniably true source.";
    summarize(text);
    return 0;
}