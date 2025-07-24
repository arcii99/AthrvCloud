//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// define sentiment categories
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

// function to determine sentiment of input string
int determineSentiment(char* input) {
    int score = 0; // initialize score to neutral
    char* posWords[] = {"happy", "love", "excited", "great"};
    char* negWords[] = {"sad", "hate", "frustrated", "bad"};

    // check for positive words
    for(int i = 0; i < sizeof(posWords)/sizeof(posWords[0]); i++) {
        if(strstr(input, posWords[i]) != NULL) {
            score += POSITIVE;
            break;
        }
    }

    // check for negative words
    for(int j = 0; j < sizeof(negWords)/sizeof(negWords[0]); j++) {
        if(strstr(input, negWords[j]) != NULL) {
            score += NEGATIVE;
            break;
        }
    }

    // return sentiment
    if(score > 0) {
        return POSITIVE;
    } else if(score < 0) {
        return NEGATIVE;
    } else {
        return NEUTRAL;
    }
}

int main() {
    char input[100];
    int sentiment;

    printf("Welcome to the Sentiment Analysis Tool!\n\n");
    printf("Enter a sentence and we'll determine its sentiment: ");
    fgets(input, 100, stdin);

    // remove newline character from input
    input[strcspn(input, "\n")] = 0;

    sentiment = determineSentiment(input);

    // print sentiment result
    if(sentiment > 0) {
        printf("\n%s\n", "That's a positive sentence!");
    } else if(sentiment < 0) {
        printf("\n%s\n", "That's a negative sentence.");
    } else {
        printf("\n%s\n", "That sentence is neutral.");
    }

    return 0;
}