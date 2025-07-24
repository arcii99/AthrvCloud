//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the word is positive
int isPositive(char word[]) {
    char positiveWords[5][20] = {"love", "great", "amazing", "happy", "wonderful"};
    int i;

    for (i = 0; i < 5; i++) {
        if (strcmp(word, positiveWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the word is negative
int isNegative(char word[]) {
    char negativeWords[5][20] = {"hate", "terrible", "sad", "disappointing", "bad"};
    int i;

    for (i = 0; i < 5; i++) {
        if (strcmp(word, negativeWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the sentiment score
int calculateSentimentScore(char sentence[]) {
    int positiveCount = 0, negativeCount = 0, score = 0, i;
    char word[20];

    // Tokenizing sentence into words and counting positive and negative words
    for (i = 0; sentence[i] != '\0'; i++) {
        int j = 0;
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            word[j] = sentence[i];
            j++;
            i++;
        }
        word[j] = '\0';
        if (isPositive(word)) {
            positiveCount++;
            score += 1;
        }
        else if (isNegative(word)) {
            negativeCount++;
            score -= 1;
        }
    }

    // Assigning a sentiment value based on score
    if (score > 0) {
        return 1;
    }
    else if (score < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

// Main function which takes user input and calculates the sentiment score
int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int sentimentScore = calculateSentimentScore(sentence);

    // Displaying the sentiment score
    if (sentimentScore > 0) {
        printf("Positive sentiment");
    }
    else if (sentimentScore < 0) {
        printf("Negative sentiment");
    }
    else {
        printf("Neutral sentiment");
    }

    return 0;
}