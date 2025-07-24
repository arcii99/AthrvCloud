//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the sentiment score of a given string
int getSentimentScore(char str[]) {
    int score = 0;
    char *word = strtok(str, " ");

    while (word != NULL) {
        if (strcmp(word, "happy") == 0 || strcmp(word, "joyful") == 0 || strcmp(word, "excited") == 0) {
            score++;
        }
        else if (strcmp(word, "sad") == 0 || strcmp(word, "heartbroken") == 0 || strcmp(word, "disappointed") == 0) {
            score--;
        }
        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    char input[1000];

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    int score = getSentimentScore(input);

    if (score > 0) {
        printf("The sentence has a positive sentiment.\n");
    }
    else if (score < 0) {
        printf("The sentence has a negative sentiment.\n");
    }
    else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}