//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100];
    int score = 0;

    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    char *firstWord = strtok(input, " ");
    while (firstWord != NULL) {
        if (strcmp(firstWord, "good") == 0 || strcmp(firstWord, "great") == 0) {
            score++;
        } else if (strcmp(firstWord, "bad") == 0 || strcmp(firstWord, "terrible") == 0) {
            score--;
        }
        firstWord = strtok(NULL, " ");
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