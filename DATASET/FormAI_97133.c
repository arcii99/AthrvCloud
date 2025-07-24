//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int score = 0;
    printf("Welcome to the Sentiment Analysis tool!\n");
    printf("Please enter a sentence to analyze: ");
    fgets(input, 100, stdin);
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (strcmp(token, "happy") == 0 || strcmp(token, "joyful") == 0 || strcmp(token, "delighted") == 0) {
            score++;
        }
        else if (strcmp(token, "sad") == 0 || strcmp(token, "depressed") == 0 || strcmp(token, "unhappy") == 0) {
            score--;
        }
        token = strtok(NULL, " ");
    }
    if (score > 0) {
        printf("Your sentence has a positive sentiment!");
    }
    else if (score == 0) {
        printf("Your sentence has a neutral sentiment.");
    }
    else {
        printf("Your sentence has a negative sentiment.");
    }
    return 0;
}