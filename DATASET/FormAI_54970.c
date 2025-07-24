//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
// This is a C program for a sentiment analysis tool.
// It takes a user inputted sentence and analyzes its sentiment as either positive or negative.

#include <stdio.h>
#include <string.h>

// Function to determine if a word is positive or negative
int determineSentiment(char word[]) {
    char positiveWords[3][10] = {"good", "happy", "love"};
    char negativeWords[3][10] = {"bad", "sad", "hate"};
    int i;

    // Check if word is positive
    for(i = 0; i < 3; i++) {
        if (strcmp(word, positiveWords[i]) == 0) {
            return 1;
        }
    }

    // Check if word is negative
    for(i = 0; i < 3; i++) {
        if (strcmp(word, negativeWords[i]) == 0) {
            return -1;
        }
    }

    // If word is not found in either list, neutral sentiment is assumed
    return 0;
}

int main() {
    char sentence[100];
    char *token;
    int sentiment = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // Tokenize sentence into individual words
    token = strtok(sentence, " ,.-\n");

    while (token != NULL) {
        sentiment += determineSentiment(token);
        token = strtok(NULL, " ,.-\n");
    }

    // Positive sentiment
    if (sentiment > 0) {
        printf("\nThe sentiment of the sentence is positive.\n");
    }
    // Negative sentiment
    else if (sentiment < 0) {
        printf("\nThe sentiment of the sentence is negative.\n");
    }
    // Neutral sentiment
    else {
        printf("\nThe sentiment of the sentence is neutral.\n");
    }

    return 0;
}