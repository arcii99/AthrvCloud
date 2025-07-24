//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000

int calculateSentimentScore(char *text) {

    int score = 0;

    if (strstr(text, "good") || strstr(text, "great") || strstr(text, "excellent"))
        score++;

    if (strstr(text, "bad") || strstr(text, "poor") || strstr(text, "terrible"))
        score--;

    return score;
}

int main() {

    char text[MAX_TEXT_SIZE];

    printf("Welcome to the Sentiment Analysis Tool\n");
    printf("Please enter the text to analyze: ");
    fgets(text, MAX_TEXT_SIZE, stdin);

    int sentimentScore = calculateSentimentScore(text);

    if (sentimentScore > 0)
        printf("\nThe sentiment score is %d. Overall, the sentiment of the text is positive. Thank you for using our tool!\n", sentimentScore);
    else if (sentimentScore == 0)
        printf("\nThe sentiment score is %d. The text is neutral. Thank you for using our tool!\n", sentimentScore);
    else
        printf("\nThe sentiment score is %d. Overall, the sentiment of the text is negative. Thank you for using our tool!\n", sentimentScore);

    return 0;
}