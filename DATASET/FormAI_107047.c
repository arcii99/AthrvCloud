//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_sentiment(char *input_text) {
    int sentiment_score = 0;
    char positive_words[10][20] = {"good", "awesome", "great", "nice", "excellent", "fantastic", "amazing", "wonderful", "perfect", "happy"};
    char negative_words[10][20] = {"bad", "terrible", "horrible", "awful", "poor", "disappointing", "sad", "frustrating", "annoying", "unpleasant"};

    // Split input text into individual words
    char *word;
    word = strtok(input_text, " ");

    while (word != NULL) {
        // Check if word is positive
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                sentiment_score++;
            }
        }

        // Check if word is negative
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, negative_words[i]) == 0) {
                sentiment_score--;
            }
        }

        word = strtok(NULL, " ");
    }

    // Determine sentiment based on total score
    if (sentiment_score > 0) {
        return 1;
    } else if (sentiment_score < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    char input_text[1000];
    printf("Please enter some text to analyze the sentiment: ");
    fgets(input_text, 1000, stdin);

    // Remove new line character from input text
    input_text[strcspn(input_text, "\n")] = 0;

    int sentiment = get_sentiment(input_text);

    if (sentiment == 1) {
        printf("The sentiment is positive.\n");
    } else if (sentiment == -1) {
        printf("The sentiment is negative.\n");
    } else {
        printf("The sentiment is neutral.\n");
    }

    return 0;
}