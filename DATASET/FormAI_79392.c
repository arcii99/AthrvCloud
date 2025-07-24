//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sentiment_score(char *input_string) {
    int pos_score = 0, neg_score = 0, word_count = 0;
    char *token = strtok(input_string, " ");
    while (token != NULL) {
        word_count++;
        if (strcmp(token, "happy") == 0 || strcmp(token, "good") == 0 || strcmp(token, "love") == 0) {
            pos_score++;
        }
        else if (strcmp(token, "sad") == 0 || strcmp(token, "bad") == 0 || strcmp(token, "hate") == 0) {
            neg_score++;
        }
        token = strtok(NULL, " ");
    }
    int total_score = pos_score - neg_score;
    if (word_count > 0) {
        return (total_score * 100) / word_count;
    }
    else {
        return 0;
    }
}

int main() {
    char input_string[1000];
    printf("Enter your sentence for sentiment analysis: ");
    fgets(input_string, 1000, stdin);
    int score = sentiment_score(input_string);
    printf("Sentiment score: %d\n", score);
    if (score > 0) {
        printf("This sentence sounds positive.\n");
    }
    else if (score < 0) {
        printf("This sentence sounds negative.\n");
    }
    else {
        printf("This sentence sounds neutral.\n");
    }
    return 0;
}