//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char text[1000], word[1000], *token;
    int posScore = 0, negScore = 0, totalScore = 0, wordCount = 0;

    printf("Enter the text to analyze: ");
    fgets(text, sizeof(text), stdin);

    printf("\nEnter the word to analyze: ");
    fgets(word, sizeof(word), stdin);

    token = strtok(text, " ");

    while (token != NULL) {
        if (strstr(token, word) != NULL) {
            posScore++;
        } else {
            negScore++;
        }

        totalScore++;
        wordCount++;

        token = strtok(NULL, " ");
    }

    printf("\nPositive Score: %d", posScore);
    printf("\nNegative Score: %d", negScore);
    printf("\nTotal Score: %d", totalScore);
    printf("\nTotal word count: %d", wordCount);

    return 0;
}