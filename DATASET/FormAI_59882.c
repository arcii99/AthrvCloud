//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 20

int main() {
    char words[MAX_WORDS][WORD_LENGTH];
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // count the number of words in the input
    int num_words = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        strncpy(words[num_words], token, WORD_LENGTH);
        num_words++;
        token = strtok(NULL, " ");
    }

    // perform sentiment analysis on the input
    int positive = 0;
    int negative = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], "happy") == 0
            || strcmp(words[i], "glad") == 0
            || strcmp(words[i], "joyful") == 0
            || strcmp(words[i], "excited") == 0) {
            positive++;
        } else if (strcmp(words[i], "sad") == 0
                   || strcmp(words[i], "unhappy") == 0
                   || strcmp(words[i], "miserable") == 0
                   || strcmp(words[i], "depressed") == 0) {
            negative++;
        }
    }

    // print out the sentiment analysis results
    if (positive > negative) {
        printf("You sound pretty happy! :)");
    } else if (positive < negative) {
        printf("Hmm, sounds like you are not too happy. :(");
    } else {
        printf("Your sentiment is neutral.");
    }

    return 0;
}