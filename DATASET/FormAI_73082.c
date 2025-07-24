//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

int main() {

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // replace punctuation with spaces
    char *punctuation = ".,:;!?";
    for (int i = 0; i < strlen(sentence); i++) {
        for (int j = 0; j < strlen(punctuation); j++) {
            if (sentence[i] == punctuation[j]) {
                sentence[i] = ' ';
                break;
            }
        }
    }

    // tokenize sentence
    char *token;
    token = strtok(sentence, " ");
    int positive_score = 0;
    int negative_score = 0;
    int neutral_score = 0;

    // loop through tokens and calculate sentiment score
    while (token != NULL) {
        if (strcmp(token, "good") == 0 || strcmp(token, "happy") == 0 || strcmp(token, "great") == 0) {
            positive_score++;
        } else if (strcmp(token, "bad") == 0 || strcmp(token, "sad") == 0 || strcmp(token, "terrible") == 0) {
            negative_score++;
        } else {
            neutral_score++;
        }
        token = strtok(NULL, " ");
    }

    // determine overall sentiment based on score
    if (positive_score > negative_score && positive_score > neutral_score) {
        printf("Overall sentiment is positive\n");
    } else if (negative_score > positive_score && negative_score > neutral_score) {
        printf("Overall sentiment is negative\n");
    } else {
        printf("Overall sentiment is neutral\n");
    }

    return 0;
}