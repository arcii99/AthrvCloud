//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char input[1000];
    int sentimentScore = 0;

    // Get user input for sentiment analysis
    printf("Please enter your text for sentiment analysis:\n");
    fgets(input, sizeof(input), stdin);

    // Calculate sentiment score
    char* token;
    token = strtok(input, " ");
    while (token != NULL) {
        if (strcmp(token, "good") == 0) {
            sentimentScore += 3;
        } else if (strcmp(token, "bad") == 0) {
            sentimentScore -= 3;
        } else if (strcmp(token, "great") == 0) {
            sentimentScore += 5;
        } else if (strcmp(token, "terrible") == 0) {
            sentimentScore -= 5;
        } else if (strcmp(token, "love") == 0) {
            sentimentScore += 4;
        } else if (strcmp(token, "hate") == 0) {
            sentimentScore -= 4;
        } else if (strcmp(token, "awesome") == 0) {
            sentimentScore += 5;
        } else if (strcmp(token, "awful") == 0) {
            sentimentScore -= 5;
        } else if (strcmp(token, "happy") == 0) {
            sentimentScore += 2;
        } else if (strcmp(token, "sad") == 0) {
            sentimentScore -= 2;
        } // Add more cases for other words
        token = strtok(NULL, " ");
    }

    // Display sentiment score
    printf("Sentiment score: %d\n", sentimentScore);

    // Determine sentiment category
    if (sentimentScore > 10) {
        printf("Very Positive\n");
    } else if (sentimentScore > 0) {
        printf("Positive\n");
    } else if (sentimentScore < -10) {
        printf("Very Negative\n");
    } else if (sentimentScore < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }

    return 0;
}