//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[1000];
    int positive = 0, negative = 0, neutral = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    // convert all characters to lowercase
    for(int i=0; i<strlen(sentence); i++) {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z') {
            sentence[i] += 32;
        }
    }

    // split sentence into individual words
    char *token = strtok(sentence, " ");
    while(token != NULL) {
        if(strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0) {
            positive++;
        }
        else if(strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "horrible") == 0) {
            negative++;
        }
        else {
            neutral++;
        }
        token = strtok(NULL, " ");
    }

    // output results
    printf("\nSentiment Analysis: \n");
    printf("Positive words: %d\n", positive);
    printf("Negative words: %d\n", negative);
    printf("Neutral words: %d\n", neutral);

    // determine overall sentiment
    if(positive > negative) {
        printf("\nThe overall sentiment of the sentence is: Positive!\n");
    }
    else if(negative > positive) {
        printf("\nThe overall sentiment of the sentence is: Negative!\n");
    }
    else {
        printf("\nThe overall sentiment of the sentence is: Neutral!\n");
    }

    return 0;
}