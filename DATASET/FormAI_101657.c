//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate sentiment score
int calculateScore(char *text) {
    int score = 0;
    char *p = strtok(text, " "); // split text by space
    while (p != NULL) {
        if (strcmp(p, "good") == 0 || strcmp(p, "great") == 0 || strcmp(p, "excellent") == 0) {
            score += 2; // add 2 for positive words
        } else if (strcmp(p, "bad") == 0 || strcmp(p, "poor") == 0 || strcmp(p, "terrible") == 0) {
            score -= 2; // subtract 2 for negative words
        } else {
            score += 1; // add 1 for neutral words
        }
        p = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char text[1000];
    printf("Enter text for sentiment analysis:\n");
    fgets(text, 1000, stdin);
    int score = calculateScore(text);

    if (score > 0) {
        printf("Sentiment score: %d (Positive)", score);
    } else if (score < 0) {
        printf("Sentiment score: %d (Negative)", score);
    } else {
        printf("Sentiment score: %d (Neutral)", score);
    }

    return 0;
}