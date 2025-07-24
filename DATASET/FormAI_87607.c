//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char userInput[100];
    int sentimentScore = 0;
    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter a sentence or paragraph to analyze: \n");
    fgets(userInput, sizeof(userInput), stdin);
    char* token = strtok(userInput, " "); // Split the user input into individual words
    while(token != NULL) {
        if(stripos(token, "good")) {
            sentimentScore++; // Increment sentiment score if word "good" is found
        }
        else if(stripos(token, "bad")) {
            sentimentScore--; // Decrement sentiment score if word "bad" is found
        }
        token = strtok(NULL, " ");
    }
    printf("The sentiment score is %d\n", sentimentScore);
    if(sentimentScore > 0) {
        printf("Overall, the sentiment is positive!\n"); // If positive sentiment score
    }
    else if(sentimentScore < 0) {
        printf("Overall, the sentiment is negative.\n"); // If negative sentiment score
    }
    else {
        printf("The sentiment is neutral.\n"); // If sentiment score is 0
    }
    return 0;
}

/* Helper function to check if a string contains a certain substring */
int stripos(const char* haystack, const char* needle) {
    char* haystackCopy = strdup(haystack);
    char* needleCopy = strdup(needle);
    if(haystackCopy && needleCopy) {
        char* p = strstr(haystackCopy, needleCopy);
        if(p) {
            return p - haystackCopy;
        }
    }
    free(haystackCopy);
    free(needleCopy);
    return -1;
}