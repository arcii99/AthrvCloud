//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[100];
    printf("Enter a sentence to analyze its sentiment:\n");
    fgets(sentence, 100, stdin);

    int sentiment_score = 0;
    char sentiment_words[10][20] = {"happy", "joy", "amazing", "excited", "fun", "love", "great", "wonderful", "nice", "fantastic"};

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        for (int i=0; i < 10; i++) {
            if (strcmp(token, sentiment_words[i]) == 0) {
                sentiment_score++;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("Sentiment analysis score: %d\n", sentiment_score);
    if (sentiment_score >= 5) {
        printf("Overall sentiment is positive!\n");
    }
    else if (sentiment_score >= 3) {
        printf("Overall sentiment is neutral.\n");
    }
    else {
        printf("Overall sentiment is negative.\n");
    }

    return 0;
}