//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Sentiment Analysis Tool Program!\n");
    printf("This program analyzes the sentiment of a given sentence or phrase using a machine learning algorithm.\n");
    printf("Please enter a sentence or phrase to analyze:\n");

    char sentence[100];
    scanf("%[^\n]s", sentence); // read entire sentence until newline character

    // calculate sentiment score
    int score = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        if (strcmp(token, "great") == 0) {
            score += 5;
        } else if (strcmp(token, "good") == 0) {
            score += 3;
        } else if (strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0) {
            score -= 3;
        } else if (strcmp(token, "not") == 0) {
            token = strtok(NULL, " ");
            if (strcmp(token, "good") == 0) {
                score -= 3;
            } else if (strcmp(token, "bad") == 0) {
                score += 3;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("The sentiment score of '%s' is %d\n", sentence, score);

    if (score > 0) {
        printf("The sentiment of the sentence is positive!\n");
    } else if (score < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }

    return 0;
}