//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    int score = 0;

    // Sample positive words
    char *positive[] = {"good", "great", "happy", "love", "awesome", "excellent", "nice"};

    // Sample negative words
    char *negative[] = {"bad", "terrible", "sad", "hate", "awful", "poor", "disappoint"};

    printf("Enter your sentence to analyze: ");
    fgets(input, MAX_SIZE, stdin);

    // Convert all characters to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Tokenize the input sentence
    char *token = strtok(input, " .,:;?!()[]{}\"\n");

    // Loop through all tokens
    while (token != NULL) {
        // Check if token is a positive word
        for (int i = 0; i < sizeof(positive) / sizeof(positive[0]); i++) {
            if (strcmp(token, positive[i]) == 0) {
                score++;
            }
        }

        // Check if token is a negative word
        for (int i = 0; i < sizeof(negative) / sizeof(negative[0]); i++) {
            if (strcmp(token, negative[i]) == 0) {
                score--;
            }
        }

        // Get the next token
        token = strtok(NULL, " .,:;?!()[]{}\"\n");
    }

    // Print the sentiment score
    if (score > 0) {
        printf("Positive sentiment! Score: %d\n", score);
    } else if (score < 0) {
        printf("Negative sentiment! Score: %d\n", score);
    } else {
        printf("Neutral sentiment! Score: %d\n", score);
    }

    return 0;
}