//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate the sentiment score of a given text.
int getSentimentScore(char *text) {
    int score = 0;
    char *word = strtok(text, " ");
    while(word != NULL) {
        if(strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            score++;
        } else if(strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "poor") == 0) {
            score--;
        }
        word = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char text[1000];
    printf("Please enter a sentence: ");
    fgets(text, 1000, stdin);
    int sentimentScore = getSentimentScore(text);
    if(sentimentScore > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if(sentimentScore == 0) {
        printf("The sentence has a neutral sentiment.\n");
    } else {
        printf("The sentence has a negative sentiment.\n");
    }
    return 0;
}