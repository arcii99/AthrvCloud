//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    int posScore = 0;
    int negScore = 0;
    int totalScore;

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    char *word = strtok(input, " "); 
    while (word != NULL) { 
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            posScore++;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "terrible") == 0) {
            negScore++;
        }
        word = strtok(NULL, " "); 
    }

    totalScore = posScore - negScore;

    printf("The sentiment score for this sentence is: %d\n", totalScore);

    if (totalScore > 0) {
        printf("The sentiment is positive! :)\n");
    } else if (totalScore < 0) {
        printf("The sentiment is negative. :(\n");
    } else {
        printf("The sentiment is neutral. :|\n");
    }

    return 0;
}