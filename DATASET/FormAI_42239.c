//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char sentence[100];
    int score = 0;
    printf("Enter the sentence to perform sentiment analysis: ");
    fgets(sentence, 100, stdin); //Gets the sentence from the user
    char *ptr = strtok(sentence, " "); //Splitting the string using strtok function

    while(ptr != NULL){
        if(strcmp(ptr, "good") == 0 || strcmp(ptr, "great") == 0 || strcmp(ptr, "excellent") == 0){
            score += 5; //Adds 5 to score if these words are encountered
        }
        else if(strcmp(ptr, "bad") == 0 || strcmp(ptr, "worst") == 0 || strcmp(ptr, "poor") == 0){
            score -= 5; //Subtracts 5 from score if these words are encountered
        }
        ptr = strtok(NULL, " "); //Moves to next token
    }

    if(score > 0){
        printf("\nPositive Sentiment"); //If score is greater than 0, positive sentiment
    }
    else if(score < 0){
        printf("\nNegative Sentiment"); //If score is less than 0, negative sentiment
    }
    else{
        printf("\nNeutral Sentiment"); //If score is 0, neutral sentiment
    }

    return 0;
}