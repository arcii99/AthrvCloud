//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate sentiment score for a given text content
int calculateSentimentScore(char* content) {
    int sentimentScore = 0;

    // list of positive and negative words used for sentiment analysis
    char positiveWords[10][20] = {"happy", "good", "great", "love", "excellent", "amazing", "excited", "fun", "pleased", "joyful"};
    char negativeWords[10][20] = {"sad", "bad", "terrible", "hate", "poor", "painful", "anger", "dislike", "unhappy", "awful"};

    // tokenize the content string and compare each word with positive/negative word list
    char* token = strtok(content, " ");
    while (token != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                sentimentScore++;
            }
            if (strcmp(token, negativeWords[i]) == 0) {
                sentimentScore--;
            }
        }
        token = strtok(NULL, " ");
    }

    return sentimentScore;
}

int main() {
    char content[1000];

    printf("Enter the content to analyze sentiment (max 1000 characters):\n");
    gets(content);

    int sentimentScore = calculateSentimentScore(content);

    if (sentimentScore > 0) {
        printf("The content has a positive sentiment score of %d.\n", sentimentScore);
    } else if (sentimentScore < 0) {
        printf("The content has a negative sentiment score of %d.\n", sentimentScore);
    } else {
        printf("The content has a neutral sentiment score of 0.\n");
    }

    return 0;
}