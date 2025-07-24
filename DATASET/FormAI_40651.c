//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of string

// Function to calculate the sentiment score of the given string
int sentimentAnalysis(char* str) {
    int score = 0; // Initialize the sentiment score to 0

    // Emotion words and their associated scores
    char* positiveWords[] = {"happy", "joyful", "excited", "love"};
    char* negativeWords[] = {"sad", "angry", "disgusted", "hate"};
    int positiveScores[] = {2, 2, 3, 5};
    int negativeScores[] = {1, 3, 4, 6};

    int numPositiveWords = sizeof(positiveWords) / sizeof(positiveWords[0]);
    int numNegativeWords = sizeof(negativeWords) / sizeof(negativeWords[0]);

    char* token = strtok(str, " "); // Get the first token
    
    while (token != NULL) {
        for (int i = 0; i < numPositiveWords; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                score += positiveScores[i];
            }
        }

        for (int i = 0; i < numNegativeWords; i++) {
            if (strcmp(token, negativeWords[i]) == 0) {
                score -= negativeScores[i];
            }
        }

        token = strtok(NULL, " "); // Move to the next token
    }

    return score;
}

int main() {
    char str[MAX_LENGTH]; // Declare a string of maximum length
    printf("Enter a string to perform sentiment analysis: ");
    fgets(str, MAX_LENGTH, stdin); // Get input from user

    int score = sentimentAnalysis(str); // Call the sentiment analysis function

    printf("The sentiment score of the given string is: %d\n", score);

    return 0;
}