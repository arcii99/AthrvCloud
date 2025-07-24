//FormAI DATASET v1.0 Category: Text Summarizer ; Style: brave
// Welcome to my Text Summarizer program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 5000
#define MAX_OUTPUT_SIZE 1000
#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 100

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentence_scores[MAX_SENTENCES] = {0};
    int total_sentences = 0;
    int max_score = 0;

    printf("Enter the text you want to summarize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Split the input into separate sentences and tokenize them
    char *sentence = strtok(input, ".?!");

    while (sentence != NULL && total_sentences < MAX_SENTENCES) {
        strncpy(sentences[total_sentences], sentence, MAX_SENTENCE_LENGTH);
        total_sentences++;
        sentence = strtok(NULL, ".?!");
    }

    // Analyze each sentence and add up its score
    for (int i = 0; i < total_sentences; i++) {
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strcmp(word, "brave") == 0) {
                sentence_scores[i]++;
            }
            word = strtok(NULL, " ");
        }
        if (sentence_scores[i] > max_score) {
            max_score = sentence_scores[i];
        }
    }

    // Build the output string with the top-scoring sentences
    strcat(output, "Summary: ");
    for (int i = 0; i < total_sentences; i++) {
        if (sentence_scores[i] == max_score) {
            strcat(output, sentences[i]);
            strcat(output, ". ");
        }
    }

    printf("\n%s\n", output);

    return 0;
}