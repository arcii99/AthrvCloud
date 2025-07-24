//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the sentiment score
int calculateSentimentScore(char *str) {
    int score = 0;

    // List of positive and negative words
    char *positiveWords[] = {"happy", "great", "love", "amazing", "fantastic", "like", "good", "wonderful", "excellent", "nice"};
    char *negativeWords[] = {"sad", "bad", "hate", "terrible", "awful", "dislike", "poor", "horrible", "unpleasant", "disappoint"};

    // Tokenization
    char *token = strtok(str, " ");

    // Loop through each token
    while (token != NULL) {

        // Check if the token is a positive word
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                score += 1;
            }
        }

        // Check if the token is a negative word
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, negativeWords[i]) == 0) {
                score -= 1;
            }
        }

        // Move to the next token
        token = strtok(NULL, " ");
    }

    return score;
}

int main() {
    // Get user input
    char userString[100];
    printf("Enter a sentence: ");
    fgets(userString, 100, stdin);

    // Calculate score
    int sentimentScore = calculateSentimentScore(userString);

    // Output sentiments
    if (sentimentScore > 0){
        printf("Positive Sentiment\n");
    } else if (sentimentScore < 0) {
        printf("Negative Sentiment\n");
    } else {
        printf("Neutral Sentiment\n");
    }

    return 0;
}