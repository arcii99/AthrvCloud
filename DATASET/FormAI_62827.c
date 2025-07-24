//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_CHARS 2000

int main() {
    char input[MAX_CHARS];
    char output[MAX_CHARS];
    char sentences[MAX_SENTENCES][MAX_CHARS];
    int sentence_count = 0;

    printf("Enter text to summarize:\n");
    fgets(input, MAX_CHARS, stdin);

    // Split input into sentences and store in sentences array
    char *ptr = strtok(input, ".?!");   // Split on these sentence-ending punctuation marks
    while (ptr != NULL && sentence_count < MAX_SENTENCES) {
        strcpy(sentences[sentence_count], ptr);
        sentence_count++;
        ptr = strtok(NULL, ".?!");
    }

    // Summarize by concatenating first sentence of each paragraph
    strcpy(output, "");
    for (int i = 0; i < sentence_count; i++) {
        if (i == 0 || sentences[i-1][strlen(sentences[i-1])-1] == '\n') {  // New paragraph
            strcat(output, sentences[i]);
        } else {   // Continuing paragraph
            strcat(output, " ");
            strcat(output, sentences[i]);
        }
    }

    printf("\nSummary:\n%s\n", output);

    return 0;
}