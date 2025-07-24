//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
#include <stdio.h>
#include <string.h>

// Function to calculate sentiment score based on the input string
int calculateSentimentScore(char *inputString) {
    int sentimentScore = 0;
    int wordWeight = 0;
    char *token = strtok(inputString, " ");

    while (token != NULL) {
        if (strcmp(token, "great") == 0) {
            wordWeight = 5;
        } else if (strcmp(token, "good") == 0) {
            wordWeight = 3;
        } else if (strcmp(token, "bad") == 0) {
            wordWeight = -3;
        } else if (strcmp(token, "terrible") == 0) {
            wordWeight = -5;
        } else {
            wordWeight = 0;
        }

        sentimentScore += wordWeight;
        token = strtok(NULL, " ");
    }

    return sentimentScore;
}

// Main function to test the sentiment analysis tool
int main() {
    char inputString[500];
    int sentimentScore;

    printf("Enter the input string: \n");
    fgets(inputString, 500, stdin);

    sentimentScore = calculateSentimentScore(inputString);

    if (sentimentScore > 0) {
        printf("The sentiment score is %d. Overall sentiment is positive.", sentimentScore);
    } else if (sentimentScore < 0) {
        printf("The sentiment score is %d. Overall sentiment is negative.", sentimentScore);
    } else {
        printf("The sentiment score is %d. Overall sentiment is neutral.", sentimentScore);
    }

    return 0;
}