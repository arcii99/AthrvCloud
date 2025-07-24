//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int count = 0;
    double positive = 0, negative = 0;

    printf("Welcome to Sentiment Analysis Tool!\n");
    printf("Please enter a sentence or phrase (max 100 characters):\n");
    fgets(input, 100, stdin);

    char *token = strtok(input, " "); // get first word

    while (token != NULL) {
        count++;

        // check for positive words
        if (strcmp(token, "love") == 0 || strcmp(token, "happy") == 0 || strcmp(token, "excited") == 0 || strcmp(token, "amazing") == 0) {
            positive++;
        }

        // check for negative words
        if (strcmp(token, "hate") == 0 || strcmp(token, "sad") == 0 || strcmp(token, "depressed") == 0 || strcmp(token, "terrible") == 0) {
            negative++;
        }

        token = strtok(NULL, " "); // get next word
    }

    // calculate sentiment score
    double sentiment = (positive - negative) / count;

    if (sentiment > 0) {
        printf("Thank you for your input! Your sentence has a positive sentiment score of %.2f.\n", sentiment);
    } else if (sentiment < 0) {
        printf("Thank you for your input! Your sentence has a negative sentiment score of %.2f.\n", sentiment);
    } else {
        printf("Thank you for your input! Your sentence has a neutral sentiment score.\n");
    }

    return 0;
}