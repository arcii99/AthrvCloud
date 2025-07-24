//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
    char statement[100];
    int positiveCount = 0, negativeCount = 0, neutralCount = 0;

    printf("Type in your statement:\n");
    fgets(statement, 100, stdin);

    char *words = strtok(statement, " .,;:\n");

    while (words != NULL) {

        if (strcmp(words, "good") == 0 || strcmp(words, "great") == 0 || strcmp(words, "excellent") == 0) {
            positiveCount++;
        } else if (strcmp(words, "bad") == 0 || strcmp(words, "terrible") == 0 || strcmp(words, "poor") == 0) {
            negativeCount++;
        } else {
            neutralCount++;
        }

        words = strtok(NULL, " .,;:\n");
    }

    if (positiveCount > negativeCount && positiveCount > neutralCount) {
        printf("Your statement is positive!\n");
    } else if (negativeCount > positiveCount && negativeCount > neutralCount) {
        printf("Your statement is negative!\n");
    } else {
        printf("Your statement is neutral!\n");
    }

    return 0;
}