//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCES 30
#define MAX_SENTENCE_LEN 200
#define MAX_SUMMARY_LEN 150

char* text_summarizer(char* text) {
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LEN];
    char summary[MAX_SUMMARY_LEN];
    int i, j, k, sentenceCount = 0;

    // split the text into individual sentences
    char *sentence = strtok(text, ".");  
    while (sentence != NULL && sentenceCount < MAX_SENTENCES) {
        strcpy(sentences[sentenceCount], sentence);
        sentenceCount++;
        sentence = strtok(NULL, ".");
    }

    // ignore last sentence if it is empty
    if (strcmp(sentences[sentenceCount-1], "") == 0) {
        sentenceCount--;
    }

    // find and append the most important sentence
    for (i = 0; i < sentenceCount-1; i++) {
        int sentenceScore = 0;
        for (j = 0; j < strlen(sentences[i]); j++) {
            if (sentences[i][j] == ' ' || sentences[i][j] == '\t') {
                sentenceScore++;
            }
        }
        for (k = i+1; k < sentenceCount; k++) {
            if (strstr(sentences[k], sentences[i]) != NULL) {
                sentenceScore++;
            }
        }
        if (sentenceScore > 2) {    // importance threshold
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
        }
    }

    return summary;
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. "
                  "Mary had a little lamb whose fleece was white as snow. "
                  "She went to the store to buy some bread, milk, and cheese. "
                  "John loves to swim in the ocean and play with his dog. "
                  "The sky is blue and the sun is shining bright today. "
                  "Roses are red, violets are blue, sugar is sweet, and so are you. ";
    char* summary = text_summarizer(text);
    printf("%s\n", summary);
    free(summary);   // deallocate memory
    return 0;
}