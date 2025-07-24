//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1024

int sentimentAnalysis(char *string) {
    int score = 0;

    // list of positive and negative words to check against
    char *positives[] = {"good", "happy", "excited", "excellent", "love"};
    char *negatives[] = {"bad", "sad", "angry", "hate", "fail"};

    // loop through string and check for positive and negative words
    char *word = strtok(string, " ");
    while (word != NULL) {
        for (int i = 0; i < sizeof(positives)/sizeof(positives[0]); i++) {
            if (strcmp(word, positives[i]) == 0) {
                score++;
            }
        }
        for (int j = 0; j < sizeof(negatives)/sizeof(negatives[0]); j++) {
            if (strcmp(word, negatives[j]) == 0) {
                score--;
            }
        }
        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    char input[MAX_CHARS];
    printf("Enter a sentence or phrase: ");
    fgets(input, MAX_CHARS, stdin);

    int result = sentimentAnalysis(input);
    if (result > 0) {
        printf("Positive sentiment detected. Score: +%d\n", result);
    } else if (result < 0) {
        printf("Negative sentiment detected. Score: %d\n", result);
    } else {
        printf("Neutral sentiment detected. Score: %d\n", result);
    }

    return 0;
}