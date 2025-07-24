//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Welcome message
    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter a sentence to determine its sentiment.\n");

    char sentence[1000];
    fgets(sentence, 1000, stdin);

    // Remove newline character from the sentence
    sentence[strcspn(sentence, "\n")] = 0;

    // Tokenize the sentence
    char *token;
    token = strtok(sentence, " ");
    int positive_count = 0;
    int negative_count = 0;

    while (token != NULL) {
        // Check if the word is positive
        if (strstr(token, "good") || strstr(token, "great") || strstr(token, "excellent")) {
            positive_count++;
        }
        // Check if the word is negative
        if (strstr(token, "bad") || strstr(token, "terrible") || strstr(token, "awful")) {
            negative_count++;
        }
        // Get the next token
        token = strtok(NULL, " ");
    }

    // Determine the overall sentiment
    if (positive_count > negative_count) {
        printf("The sentence has a positive sentiment.\n");
    } else if (negative_count > positive_count) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}