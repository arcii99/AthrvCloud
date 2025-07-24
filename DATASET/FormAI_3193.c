//FormAI DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 10
#define MAX_SENTENCE_LENGTH 100

int main() {
    // Initializing variables
    char article[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    char summary[MAX_SENTENCE_LENGTH];
    int sentence_scores[MAX_SENTENCES];
    int summary_length = 0;
    int num_sentences = 0;
    int i, j;

    // Get the article
    printf("Enter the article:\n");
    for(i = 0; i < MAX_SENTENCES; i++) {
        fgets(article[i], MAX_SENTENCE_LENGTH, stdin);
        if(article[i][0] == '\n') {
            num_sentences = i;
            break;
        }
    }

    // Calculate the score for each sentence
    for(i = 0; i < num_sentences; i++) {
        sentence_scores[i] = 0;
        for(j = 0; j < strlen(article[i]); j++) {
            char c = article[i][j];
            if(c == ' ' || c == '\t' || c == '\n') {
                continue;
            }
            else if(c >= 'A' && c <= 'Z') {
                sentence_scores[i] += (int)(c - 'A' + 1);
            }
            else if(c >= 'a' && c <= 'z') {
                sentence_scores[i] += (int)(c - 'a' + 1);
            }
        }
    }

    // Select the highest scoring sentences for the summary
    for(i = 0; i < num_sentences; i++) {
        if(sentence_scores[i] > 0) {
            for(j = 0; j < strlen(article[i]); j++) {
                summary[summary_length++] = article[i][j];
            }
            summary[summary_length++] = ' ';
        }
        if(summary_length > MAX_SENTENCE_LENGTH) {
            break;
        }
    }

    // Print the summary
    printf("\nSummary:\n%s", summary);
    return 0;
}