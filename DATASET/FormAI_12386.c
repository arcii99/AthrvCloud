//FormAI DATASET v1.0 Category: Text Summarizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100000
#define MAX_OUTPUT_SIZE 10000
#define MAX_SENTENCES 1000
#define MAX_WORDS 1000

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE] = {0};
    char sentences[MAX_SENTENCES][MAX_WORDS] = {0};
    int sentenceCount = 0;
    int wordCount = 0;

    // Read input from user
    printf("Enter input text: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Split input into sentences
    char *token = strtok(input, ".!?\n");
    while (token != NULL && sentenceCount < MAX_SENTENCES) {
        // Trim leading and trailing spaces
        while (isspace(*token)) token++;
        char *end = token + strlen(token) - 1;
        while (end > token && isspace(*end)) end--;
        *(end+1) = '\0';

        // Copy sentence to sentences array
        strncpy(sentences[sentenceCount], token, MAX_WORDS-1);
        sentenceCount++;
        token = strtok(NULL, ".!?\n");
    }

    // Calculate score for each sentence
    int scores[MAX_SENTENCES] = {0};
    for (int i = 0; i < sentenceCount; i++) {
        // Count number of words in sentence
        char *wordToken = strtok(sentences[i], " \n");
        while (wordToken != NULL && wordCount < MAX_WORDS) {
            wordCount++;
            wordToken = strtok(NULL, " \n");
        }
        scores[i] = wordCount;
        wordCount = 0;
    }

    // Find top 5 sentences with highest score
    int top5[MAX_SENTENCES] = {0};
    for (int i = 0; i < 5; i++) {
        int maxIndex = 0;
        for (int j = 0; j < sentenceCount; j++) {
            if (scores[j] > scores[maxIndex]) {
                maxIndex = j;
            }
        }
        top5[i] = maxIndex;
        scores[maxIndex] = 0;
    }

    // Construct summary from top 5 sentences
    for (int i = 0; i < 5; i++) {
        strcat(output, sentences[top5[i]]);
        strcat(output, ". ");
    }

    // Print summary
    printf("Summary: %s\n", output);

    return 0;
}