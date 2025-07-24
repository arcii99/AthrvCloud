//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 1000

int get_sentiment_score(char* text);

int main() {
    char text[MAX_TEXT_LEN];
    printf("Enter some text to analyze sentiment:\n");
    fgets(text, MAX_TEXT_LEN, stdin);

    int score = get_sentiment_score(text);
    if (score < 0) {
        printf("The sentiment of the text is negative.\n");
    } else if (score == 0) {
        printf("The sentiment of the text is neutral.\n");
    } else {
        printf("The sentiment of the text is positive.\n");
    }

    return 0;
}

int get_sentiment_score(char* text) {
    int score = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        if (strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0) {
            score++;
        } else if (strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0) {
            score--;
        }
        token = strtok(NULL, " ");
    }
    return score;
}