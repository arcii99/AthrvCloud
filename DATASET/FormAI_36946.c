//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* get_sentiment(int score) {
    if (score < -5) {
        return "Terribly negative!";
    } else if (score < 0) {
        return "Negative";
    } else if (score == 0) {
        return "Neutral";
    } else if (score < 5) {
        return "Positive";
    } else {
        return "Terribly positive!";
    }
}

int main() {
    char text[1000];
    int sentiment_score = 0;
    printf("Welcome to the Retro Sentiment Analysis Tool!\n");
    printf("Enter some text to analyze: ");
    fgets(text, 1000, stdin);
    char* token = strtok(text, " ,.?\n'\"");
    while(token != NULL) {
        int token_score = 0;
        int len = strlen(token);
        for (int i=0; i<len; i++) {
            token_score += (int)token[i]; //calculate score for each character
        }
        sentiment_score += token_score; //add score to overall sentiment score
        token = strtok(NULL, " ,.?\n'\"");
    }
    char* sentiment = get_sentiment(sentiment_score);
    printf("\nYour text has a sentiment score of %d.\nSentiment: %s\n", sentiment_score, sentiment);
    return 0;
}