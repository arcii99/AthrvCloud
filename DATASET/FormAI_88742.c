//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];

    printf("Enter a sentence for sentiment analysis:\n");

    fgets(input, 1000, stdin);
    input[strcspn(input, "\n")] = 0; // removes newline character from input

    int score = 0;
    char *token = strtok(input, " ");

    while (token != NULL) {
        if (strcmp(token, "love") == 0) {
            score += 2;
        } else if (strcmp(token, "like") == 0 || strcmp(token, "good") == 0) {
            score += 1;
        } else if (strcmp(token, "hate") == 0) {
            score -= 2;
        } else if (strcmp(token, "dislike") == 0 || strcmp(token, "bad") == 0) {
            score -= 1;
        }
        token = strtok(NULL, " ");
    }

    if (score > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (score < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}