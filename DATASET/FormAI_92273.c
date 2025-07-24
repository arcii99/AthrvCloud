//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to evaluate the sentiment of a text
// returns a value between -1 and 1 (-1 being negative and 1 being positive)
float evaluate_sentiment(char *text) {
    float sentiment_score = 0.0;
    int len = strlen(text);
    int positive_count = 0, negative_count = 0;

    // list of positive words
    char *positive_words[] = {"happy", "great", "excited", "love", "amazing", "wonderful", "fantastic"};
    int positive_words_count = 7;

    // list of negative words
    char *negative_words[] = {"sad", "bad", "angry", "hate", "terrible", "awful", "horrible"};
    int negative_words_count = 7;

    // iterate through each word in the text
    char *token = strtok(text, " ");
    while (token != NULL) {
        // check if the word is positive
        for (int i = 0; i < positive_words_count; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_count++;
            }
        }

        // check if the word is negative
        for (int i = 0; i < negative_words_count; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                negative_count++;
            }
        }

        token = strtok(NULL, " ");
    }

    // calculate the sentiment score
    if (positive_count == 0 && negative_count == 0) {
        sentiment_score = 0.0;
    } else if (positive_count > negative_count) {
        sentiment_score = (float) (positive_count - negative_count) / (float) (positive_count + negative_count);
    } else {
        sentiment_score = -1.0 * (float) (negative_count - positive_count) / (float) (positive_count + negative_count);
    }

    return sentiment_score;
}

int main() {
    char text[1000];
    float sentiment_score;

    printf("Enter some text: ");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = 0; // remove newline character from input

    sentiment_score = evaluate_sentiment(text);

    printf("Sentiment score: %.2f\n", sentiment_score);

    return 0;
}