//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int analyze_sentiment(char *input) {
    int sentiment_score = 0;

    // Convert input to lowercase
    char *lowercase_input = (char *) malloc(strlen(input) + 1);
    char *c = input;
    int i = 0;
    while (*c != '\0') {
        lowercase_input[i] = tolower(*c);
        c++;
        i++;
    }
    lowercase_input[i] = '\0';

    // Check for positive keywords
    if (strstr(lowercase_input, "happy") != NULL ||
        strstr(lowercase_input, "excited") != NULL ||
        strstr(lowercase_input, "amazing") != NULL ||
        strstr(lowercase_input, "awesome") != NULL ||
        strstr(lowercase_input, "great") != NULL) {
        sentiment_score++;
    }

    // Check for negative keywords
    if (strstr(lowercase_input, "sad") != NULL ||
        strstr(lowercase_input, "depressed") != NULL ||
        strstr(lowercase_input, "awful") != NULL ||
        strstr(lowercase_input, "terrible") != NULL ||
        strstr(lowercase_input, "bad") != NULL) {
        sentiment_score--;
    }

    // Check for intensifiers
    if (strstr(lowercase_input, "very") != NULL ||
        strstr(lowercase_input, "extremely") != NULL ||
        strstr(lowercase_input, "incredibly") != NULL) {
        sentiment_score *= 2;
    }

    // Free memory
    free(lowercase_input);

    return sentiment_score;
}

int main() {
    // Test the program
    char *input1 = "I am so excited for the concert tonight!";
    int score1 = analyze_sentiment(input1);
    printf("Input: %s\nSentiment score: %d\n\n", input1, score1);

    char *input2 = "I feel sad that my dog ran away.";
    int score2 = analyze_sentiment(input2);
    printf("Input: %s\nSentiment score: %d\n\n", input2, score2);

    char *input3 = "The food at the restaurant was very delicious.";
    int score3 = analyze_sentiment(input3);
    printf("Input: %s\nSentiment score: %d\n\n", input3, score3);

    return 0;
}