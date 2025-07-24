//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate sentiment score for a phrase
int calculateSentiment(char phrase[]) {
    int sentimentScore = 0;
    char *word = strtok(phrase, " ");
    while(word != NULL) {
        // check if word is positive or negative
        if(strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            sentimentScore += 1;
        }
        else if(strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
            sentimentScore -= 1;
        }
        word = strtok(NULL, " ");
    }
    return sentimentScore;
}

int main() {
    char phrase[100];
    printf("Enter a phrase to analyze sentiment: ");
    fgets(phrase, 100, stdin);
    // remove newline character from input
    phrase[strcspn(phrase, "\n")] = 0;
    
    int sentimentScore = calculateSentiment(phrase);
    if(sentimentScore > 0) {
        printf("The sentiment of \"%s\" is positive with a score of %d\n", phrase, sentimentScore);
    }
    else if(sentimentScore < 0) {
        printf("The sentiment of \"%s\" is negative with a score of %d\n", phrase, sentimentScore);
    }
    else {
        printf("The sentiment of \"%s\" is neutral with a score of %d\n", phrase, sentimentScore);
    }
    return 0;
}