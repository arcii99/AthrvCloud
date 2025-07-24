//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <string.h>

void main() {
    char text[1000];
    int positiveCount = 0, negativeCount = 0, neutralCount = 0;

    printf("Enter some text to analyze the sentiment: ");
    fgets(text, 1000, stdin);

    // Splitting words
    char *token = strtok(text, " ");

    while (token != NULL) {
        // Matching words with sentiment keywords
        if (strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0) {
            positiveCount++;
        } else if (strcmp(token, "bad") == 0 || strcmp(token, "poor") == 0 || strcmp(token, "terrible") == 0) {
            negativeCount++;
        } else {
            neutralCount++;
        }

        token = strtok(NULL, " ");
    }

    printf("Analysis Result:\n");
    printf("Positive Keywords count: %d\n", positiveCount);
    printf("Negative Keywords count: %d\n", negativeCount);
    printf("Neutral Keywords count: %d\n", neutralCount);

    if (positiveCount > negativeCount) {
        printf("Overall Sentiment: Positive");
    } else if (positiveCount < negativeCount) {
        printf("Overall Sentiment: Negative");
    } else {
        printf("Overall Sentiment: Neutral");
    }
}