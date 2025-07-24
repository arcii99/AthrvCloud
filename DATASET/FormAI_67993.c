//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
// A dynamic C program for sentiment analysis of text
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate sentiment score of a string
int calculateSentiment(char* str) {
    int score = 0;
    char* word = strtok(str, " ");
    while (word != NULL) {
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "happy") == 0) {
            score++;
        }
        else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "sad") == 0) {
            score--;
        }
        word = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char text[1000];
    printf("Enter the text to analyze: ");
    scanf("%[^\n]%*c", text);
    int sentimentScore = calculateSentiment(text);
    if (sentimentScore > 0) {
        printf("Positive sentiment with score %d\n", sentimentScore);
    }
    else if (sentimentScore < 0) {
        printf("Negative sentiment with score %d\n", sentimentScore);
    }
    else {
        printf("Neutral sentiment\n");
    }
    return 0;
}