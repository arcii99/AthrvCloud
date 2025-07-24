//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char review[1000];
    int positiveWords = 0, negativeWords = 0;

    printf("Welcome to the Cheerful Sentiment Analysis Tool!\n");
    printf("Enter your review below:\n");

    fgets(review, 1000, stdin);

    char *words = strtok(review, " ");

    while (words != NULL) {
        if (strcmp(words, "amazing") == 0 || strcmp(words, "awesome") == 0
                || strcmp(words, "fantastic") == 0 || strcmp(words, "great") == 0
                || strcmp(words, "excellent") == 0 || strcmp(words, "fantabulous") == 0) {
            positiveWords++;
        } else if (strcmp(words, "horrible") == 0 || strcmp(words, "terrible") == 0
                || strcmp(words, "awful") == 0 || strcmp(words, "bad") == 0
                || strcmp(words, "poor") == 0 || strcmp(words, "not good") == 0) {
            negativeWords++;
        }
        words = strtok(NULL, " ");
    }

    if (positiveWords > negativeWords) {
        printf("Your review is overwhelmingly positive! Keep shining!\n");
    } else if (positiveWords < negativeWords) {
        printf("Your review is quite negative. But don't worry, tomorrow is a new day!\n");
    } else {
        printf("Your review is balanced with equal positive and negative words. Keep it neutral!\n");
    }

    return 0;
}