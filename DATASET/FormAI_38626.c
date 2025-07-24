//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char userInput[1000];

    printf("Enter a sentence to analyze: ");
    fgets(userInput, 1000, stdin);

    int positiveWords = 0;
    int negativeWords = 0;

    char* token = strtok(userInput, " ,.-");
    while (token != NULL) {
        if (strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0) {
            positiveWords++;
        } else if (strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0) {
            negativeWords++;
        }
        token = strtok(NULL, " ,.-");
    }

    if (positiveWords > negativeWords) {
        printf("The sentence is mostly positive!\n");
    } else if (negativeWords > positiveWords) {
        printf("The sentence is mostly negative!\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}