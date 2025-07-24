//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char userInput[1000];
    char positiveWords[1000] = "good,great,happy,love,nice,excellent,fun,awesome,wonderful,perfect";
    char negativeWords[1000] = "bad,terrible,sad,hate,dislike,poor,disappointing, frustrating";
    int positiveCount = 0;
    int negativeCount = 0;
    int neutralCount = 0;

    printf("Enter your text to be analyzed:\n");
    fgets(userInput, sizeof(userInput), stdin);

    char *token = strtok(userInput, " ");

    while (token != NULL) {
        if (strstr(positiveWords, token) != NULL) {
            positiveCount++;
        } else if (strstr(negativeWords, token) != NULL) {
            negativeCount++;
        } else {
            neutralCount++;
        }
        token = strtok(NULL, " ");
    }

    if (positiveCount > negativeCount && positiveCount > neutralCount) {
        printf("Sentiment Analysis Result: Positive");
        return 0;
    }

    if (negativeCount > positiveCount && negativeCount > neutralCount) {
        printf("Sentiment Analysis Result: Negative");
        return 0;
    }

    printf("Sentiment Analysis Result: Neutral");
    return 0;
}