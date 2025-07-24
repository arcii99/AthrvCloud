//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for sentiment analysis
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

// function to analyze sentiment
int sentiment_analysis(char *input) {
    int score = 0;
    char *token;

    // tokenize input string
    token = strtok(input, " ");

    while (token != NULL) {
        // check if token matches any positive word
        if (strcmp(token, "good") == 0 || strcmp(token, "happy") == 0 || strcmp(token, "great") == 0) {
            score += POSITIVE;
        }

        // check if token matches any negative word
        if (strcmp(token, "bad") == 0 || strcmp(token, "sad") == 0 || strcmp(token, "terrible") == 0) {
            score += NEGATIVE;
        }

        token = strtok(NULL, " ");
    }

    // return sentiment score
    if (score > 0) {
        return POSITIVE;
    } else if (score < 0) {
        return NEGATIVE;
    } else {
        return NEUTRAL;
    }
}

int main() {
    char input[1000];
    int sentiment_score;

    printf("Enter a sentence for sentiment analysis: ");
    fgets(input, sizeof(input), stdin);

    // remove newline character from input
    input[strcspn(input, "\n")] = 0;

    sentiment_score = sentiment_analysis(input);

    // print sentiment score
    if (sentiment_score == POSITIVE) {
        printf("Positive sentiment detected\n");
    } else if (sentiment_score == NEGATIVE) {
        printf("Negative sentiment detected\n");
    } else {
        printf("Neutral sentiment detected\n");
    }

    return 0;
}