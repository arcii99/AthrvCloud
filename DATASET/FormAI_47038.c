//FormAI DATASET v1.0 Category: Text Summarizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_SENTENCES 5

int main()
{
    char text[] = "The quick brown fox jumps over the lazy dog. This is a sample text for summarization.";

    char *words[MAX_WORDS];
    int wordCount = 0;

    char *sentences[MAX_SENTENCES];
    int sentenceCount = 0;

    // Tokenize text into words
    char *token = strtok(text, " ");
    while (token != NULL && wordCount < MAX_WORDS) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    // Find the midpoint of the word array
    int midpoint = wordCount / 2;

    // Concatenate the first half of the words into a summary sentence
    char *summary = malloc(sizeof(char) * 100);
    *summary = '\0';
    for (int i = 0; i < midpoint; i++) {
        strcat(summary, words[i]);
        strcat(summary, " ");
    }

    // Tokenize text into sentences
    token = strtok(text, ".\n");
    while (token != NULL && sentenceCount < MAX_SENTENCES) {
        sentences[sentenceCount++] = token;
        token = strtok(NULL, ".\n");
    }

    // Print out the summary and the first sentence of the original text
    printf("%s.\n", summary);
    printf("%s.\n", sentences[0]);

    return 0;
}