//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate sentiment score
int calculate_sentiment_score(char input[]) {
    // Initialize positive and negative word lists
    char positive_words[5][15] = {"happy", "great", "amazing", "love", "awesome"};
    char negative_words[5][15] = {"sad", "bad", "terrible", "hate", "awful"};

    int sentiment_score = 0;

    // Split input string into individual words
    char* word = strtok(input, " ");

    while (word != NULL) {
        // Check if word is positive or negative and update sentiment score accordingly
        for(int i = 0; i < 5; i++) {
            if (strcmp(positive_words[i], word) == 0) {
                sentiment_score++;
                break;
            }
            if (strcmp(negative_words[i], word) == 0) {
                sentiment_score--;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    return sentiment_score;
}

int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    // Remove newline character added by fgets
    input[strlen(input) - 1] = '\0';

    int sentiment_score = calculate_sentiment_score(input);

    // Output sentiment score
    printf("Sentiment score for \"%s\" is: %d\n", input, sentiment_score);

    return 0;
}