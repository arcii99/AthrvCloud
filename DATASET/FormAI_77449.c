//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getSentiment(char *input);

int main() {
    char sentence[100];
    printf("Enter a sentence for sentiment analysis: ");
    fgets(sentence, 100, stdin);
    int sentiment = getSentiment(sentence);
    switch (sentiment) {
        case 0:
            printf("The sentence is neutral.\n");
            break;
        case 1:
            printf("The sentence has a positive sentiment.\n");
            break;
        case -1:
            printf("The sentence has a negative sentiment.\n");
            break;
        default:
            printf("Error: Invalid sentiment.\n");
            break;
    }
    return 0;
}

int getSentiment(char *input) {
    char posWords[4][20] = {"good", "great", "excellent", "wonderful"};
    char negWords[4][20] = {"bad", "terrible", "awful", "horrible"};
    char *token;
    int score = 0;
    token = strtok(input, " ");
    while (token != NULL) {
        for (int i = 0; i < 4; i++) {
            if (strcmp(token, posWords[i]) == 0) {
                score++;
            } else if (strcmp(token, negWords[i]) == 0) {
                score--;
            }
        }
        token = strtok(NULL, " ");
    }
    if (score > 0) {
        return 1;
    } else if (score < 0) {
        return -1;
    } else {
        return 0;
    }
}