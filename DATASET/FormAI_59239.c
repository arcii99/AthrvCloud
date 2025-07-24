//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Array of positive words
char *positive_words[] = {"good", "great", "excellent", "fantastic", "awesome",
                          "amazing", "wonderful", "perfect", "nice", "pleased"};

// Array of negative words
char *negative_words[] = {"bad", "awful", "terrible", "horrible", "unhappy",
                          "disappointed", "mad", "angry", "inferior", "hate"};

// Function to check if a word is in the positive words array
int is_positive(char *word) {
    // Loop through all of the positive words
    for (int i = 0; i < 10; i++) {
        // If the word matches, return 1 (true)
        if (strcmp(word, positive_words[i]) == 0) {
            return 1;
        }
    }
    // If the word is not in the positive words array, return 0 (false)
    return 0;
}

// Function to check if a word is in the negative words array
int is_negative(char *word) {
    // Loop through all of the negative words
    for (int i = 0; i < 10; i++) {
        // If the word matches, return 1 (true)
        if (strcmp(word, negative_words[i]) == 0) {
            return 1;
        }
    }
    // If the word is not in the negative words array, return 0 (false)
    return 0;
}

// Main function - performs the sentiment analysis
int main() {
    // Declare variables
    char input[10000];
    int positive_count = 0, negative_count = 0;

    // Prompt the user for input
    printf("Enter some text: ");
    fgets(input, 10000, stdin);

    // Split the input into individual words
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Remove any newline characters from the end of the word
        if (token[strlen(token) - 1] == '\n') {
            token[strlen(token) - 1] = '\0';
        }

        // Check if the word is positive or negative
        if (is_positive(token)) {
            positive_count++;
        } else if (is_negative(token)) {
            negative_count++;
        }

        // Get the next word in the input
        token = strtok(NULL, " ");
    }

    // Calculate the total sentiment score
    int sentiment_score = positive_count - negative_count;

    // Print the sentiment analysis results
    printf("Positive words: %d\n", positive_count);
    printf("Negative words: %d\n", negative_count);
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}