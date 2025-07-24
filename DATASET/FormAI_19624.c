//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("This is a sentiment analysis tool! \n");
    char input[1000];
    int positiveCount = 0;
    int negativeCount = 0;
    int neutralCount = 0;
    char posWords[7][20] = {"good", "happy", "fantastic", "excellent", "amazing", "love", "peace"};
    char negWords[7][20] = {"bad", "sad", "disappointing", "terrible", "hate", "angry", "painful"};
    printf("Enter a sentence to analyze: ");
    fgets(input, 1000, stdin);
    char *token;
    token = strtok(input, " .\n");
    while (token != NULL) {
        for(int i=0; i<7; i++){
            if(strcasecmp(token, posWords[i]) == 0){
                positiveCount++;
                break;
            }
            else if(strcasecmp(token, negWords[i]) == 0){
                negativeCount++;
                break;
            }
        }
        token = strtok(NULL, " .\n");
    }
    neutralCount = strlen(input) - positiveCount - negativeCount;
    printf("Sentiment Analysis Results: \n");
    printf("Positive words count: %d\n", positiveCount);
    printf("Negative words count: %d\n", negativeCount);
    printf("Neutral words count: %d\n", neutralCount);
    
    // Custom messages based on sentiment
    if(positiveCount > negativeCount){
        printf("Looks like you had a positive experience! :D\n");
    }
    else if(negativeCount > positiveCount){
        printf("Looks like you had a negative experience :( \n");
    }
    else{
        printf("Your experience seems neutral :| \n");
    }
    return 0;
}