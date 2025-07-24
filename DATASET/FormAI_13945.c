//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Our text summarizer function
void summarize(char *text) {
    int words_count = 0;
    int sentences_count = 0;

    // Count the number of words and sentences
    char *p = strtok(text, " .");
    while (p != NULL) {
        words_count++;
        if (strchr(".!?;", p[strlen(p)-1]) != NULL) {
            sentences_count++;
        }
        p = strtok(NULL, " .");
    }

    // Allocate memory for storing sentences
    char **sentences = malloc(sentences_count * sizeof(char *));
    if (sentences == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    // Fill the sentences array
    p = strtok(text, ".!?");
    int i = 0;
    while (p != NULL) {
        sentences[i] = malloc(strlen(p) * sizeof(char));
        if (sentences[i] == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }
        strncpy(sentences[i], p, strlen(p));
        sentences[i][strlen(p)] = '\0';
        i++;
        p = strtok(NULL, ".!?");
    }

    // Compute the score for each sentence
    float *scores = malloc(sentences_count * sizeof(float));
    if (scores == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    for (i = 0; i < sentences_count; i++) {
        scores[i] = 0;
        p = strtok(sentences[i], " ");
        while (p != NULL) {
            if (strlen(p) > 5) {
                scores[i]++;
            }
            p = strtok(NULL, " ");
        }
        scores[i] /= words_count;
    }

    // Print the summary
    printf("Summary:\n");
    for (i = 0; i < sentences_count; i++) {
        if (scores[i] > 0.1) {
            printf("%s.\n", sentences[i]);
        }
    }

    // Clean up
    for (i = 0; i < sentences_count; i++) {
        free(sentences[i]);
    }
    free(sentences);
    free(scores);
}

int main() {
    char text[] = "The quick brown fox jumped over the lazy dog. Peter Piper picked a peck of pickled peppers. How much wood would a woodchuck chuck, if a woodchuck could chuck wood?";
    summarize(text);
    return 0;
}