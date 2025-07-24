//FormAI DATASET v1.0 Category: Text Summarizer ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 2000
#define MAX_SENTENCES 20

int main() {
    char text[MAX_INPUT_SIZE];
    fgets(text, MAX_INPUT_SIZE, stdin);

    int sentence_count = 0;
    char *sentence_array[MAX_SENTENCES];

    char *token = strtok(text, ".");
    while (token != NULL && sentence_count < MAX_SENTENCES) {
        sentence_array[sentence_count++] = token;
        token = strtok(NULL, ".");
    }

    int word_count[MAX_SENTENCES] = {0};
    for (int i = 0; i < sentence_count; i++) {
        char *word = strtok(sentence_array[i], " ");
        while (word != NULL) {
            word_count[i]++;
            word = strtok(NULL, " ");
        }
    }

    int max_words = 0;
    for (int i = 0; i < sentence_count; i++) {
        if (word_count[i] > max_words) {
            max_words = word_count[i];
        }
    }

    char *summary[MAX_SENTENCES];
    int summary_length = 0;
    for (int i = 0; i < sentence_count; i++) {
        if ((float) word_count[i] / max_words > 0.7) {
            summary[summary_length++] = sentence_array[i];
        }
    }

    for (int i = 0; i < summary_length; i++) {
        printf("%s. ", summary[i]);
    }

    return 0;
}