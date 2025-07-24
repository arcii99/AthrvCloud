//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate sentiment score
int sentiment_analysis(char *input_text) {
    int positive_words = 0, negative_words = 0, score = 0;

    // List of positive and negative words
    char *positive[] = {"happy", "love", "success", "awesome", "excited"};
    char *negative[] = {"hate", "failure", "bad", "disappointed", "angry"};

    char *token = strtok(input_text, " ");

    // Iterate through every word in the input text
    while (token != NULL) {
        int is_positive = 0, is_negative = 0;
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positive[i]) == 0) {
                positive_words++;
                is_positive = 1;
                break;
            }
            if (strcmp(token, negative[i]) == 0) {
                negative_words++;
                is_negative = 1;
                break;
            }
        }
        // Calculate sentiment score based on word classification
        score += is_positive - is_negative;
        token = strtok(NULL, " ");
    }

    printf("Positive words: %d\n", positive_words);
    printf("Negative words: %d\n", negative_words);
    printf("Sentiment score: %d\n", score);

    return score;
}

int main() {
    char input_text[1000];
    printf("Enter some text to analyze sentiment: ");
    fgets(input_text, 1000, stdin);
    int score = sentiment_analysis(input_text);
    if (score > 0) {
        printf("Overall sentiment: positive\n");
    } else if (score < 0) {
        printf("Overall sentiment: negative\n");
    } else {
        printf("Overall sentiment: neutral\n");
    }
    return 0;
}