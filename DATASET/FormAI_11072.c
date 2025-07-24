//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    int positive_words = 0, negative_words = 0;

    printf("Enter your sentence: ");
    fgets(input, 1000, stdin);   // Read user input

    char *word = strtok(input, " ");   // Tokenizing input sentence
    while (word != NULL) {
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            positive_words++;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "terrible") == 0) {
            negative_words++;
        }
        word = strtok(NULL, " ");
    }

    if (positive_words > negative_words) {
        printf("This sentence has a positive sentiment.\n");
    } else if (positive_words < negative_words) {
        printf("This sentence has a negative sentiment.\n");
    } else {
        printf("This sentence has a neutral sentiment.\n");
    }

    return 0;
}