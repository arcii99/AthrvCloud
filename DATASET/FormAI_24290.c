//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the function prototypes
char* get_sentiment(int score);
int analyse_sentiment(char *sentence);

int main()
{
    char sentence[1000];

    printf("Please enter a sentence: ");
    fgets(sentence, 1000, stdin);

    int score = analyse_sentiment(sentence);

    // Print the result of the analysis
    printf("The sentiment of the sentence is: %s\n", get_sentiment(score));

    return 0;
}

// Function to analyze the sentiment of the sentence
int analyse_sentiment(char *sentence) {
    int score = 0;
    char *token = strtok(sentence, " ");

    while(token) {
        if (strcmp(token, "good") == 0) {
            score += 2;
        } else if (strcmp(token, "bad") == 0) {
            score -= 2;
        } else if (strcmp(token, "amazing") == 0) {
            score += 3;
        } else if (strcmp(token, "terrible") == 0) {
            score -= 3;
        } else if (strcmp(token, "awesome") == 0) {
            score += 4;
        } else if (strcmp(token, "horrible") == 0) {
            score -= 4;
        }

        token = strtok(NULL, " ");
    }

    return score;
}

// Function to get the sentiment from the score
char* get_sentiment(int score) {
    if(score > 0) {
        return "Positive";
    } else if (score < 0) {
        return "Negative";
    } else {
        return "Neutral";
    }
}