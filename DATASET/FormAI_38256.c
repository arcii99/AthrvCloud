//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// function to perform sentiment analysis
void sentiment_analysis(char *input_string) {
    // define array of positive and negative words
    char *positive_words[] = {"good", "excellent", "great", "awesome", "fantastic", "superb", "amazing"};
    char *negative_words[] = {"bad", "poor", "terrible", "awful", "horrible", "disgusting", "dreadful"};

    // initialize counters for positive and negative sentiment
    int pos_sentiment = 0;
    int neg_sentiment = 0;

    // tokenize the input string
    char *token = strtok(input_string, " ");
    while (token != NULL) {
        // check if the token is a positive word
        for (int i = 0; i < sizeof(positive_words) / sizeof(positive_words[0]); i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                pos_sentiment++;
            }
        }
        // check if the token is a negative word
        for (int i = 0; i < sizeof(negative_words) / sizeof(negative_words[0]); i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                neg_sentiment++;
            }
        }
        // move to the next token
        token = strtok(NULL, " ");
    }

    // determine overall sentiment
    if (pos_sentiment > neg_sentiment) {
        printf("Overall sentiment is positive!\n");
    }
    else if (neg_sentiment > pos_sentiment) {
        printf("Overall sentiment is negative!\n");
    }
    else {
        printf("Overall sentiment is neutral!\n");
    }
}

int main() {
    // read input string from user
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a string to analyze sentiment: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    // perform sentiment analysis
    sentiment_analysis(input_string);

    return 0;
}