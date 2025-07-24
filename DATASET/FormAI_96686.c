//FormAI DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 200

int main() {
    char input[MAX_INPUT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];
    int i, j, k, len, count = 0;

    printf("Enter your text:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin); // get user input

    len = strlen(input);
    if (len > MAX_INPUT_LENGTH-2) {
        printf("Input too long. Maximum length is %d characters.", MAX_INPUT_LENGTH-2);
        return 1;
    }

    // tokenize input into sentences
    char *sentences[len];
    char *token = strtok(input, ".!?");
    while (token != NULL) {
        sentences[count] = token;
        count++;
        token = strtok(NULL, ".!?");
    }

    // score each sentence based on frequency of words
    int scores[count];
    for (i = 0; i < count; i++) {
        scores[i] = 0;
        char *words[len];
        int word_count = 0;
        char *word_token = strtok(sentences[i], " \n\t");
        while (word_token != NULL) {
            words[word_count] = word_token;
            word_count++;
            word_token = strtok(NULL, " \n\t");
        }
        for (j = 0; j < word_count; j++) {
            for (k = 0; k < count; k++) {
                if (k != i && strstr(sentences[k], words[j]) != NULL) {
                    scores[i]++;
                }
            }
        }
    }

    // find highest-scoring sentence and add to summary
    for (i = 0; i < MAX_SUMMARY_LENGTH; i++) {
        int max_score = -1;
        int max_index = -1;
        for (j = 0; j < count; j++) {
            if (scores[j] > max_score) {
                max_score = scores[j];
                max_index = j;
            }
        }
        if (max_score == -1) {
            break; // no more high-scoring sentences
        }
        char *p = strtok(sentences[max_index], " \n\t");
        while (p != NULL) {
            strcat(summary, p);
            strcat(summary, " ");
            p = strtok(NULL, " \n\t");
        }
        scores[max_index] = -1; // don't use this sentence again
    }

    printf("Summary:\n%s\n", summary);
    return 0;
}