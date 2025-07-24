//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <string.h>

// Define a struct to store the sentiment analysis result
typedef struct SentimentResult {
    int positive;
    int negative;
    int neutral;
} SentimentResult;

// Function to analyze the sentiment of a given text
SentimentResult analyze_sentiment(char *text) {
    SentimentResult result = {0, 0, 0};

    // Define a list of positive and negative words
    char *positive_words[] = {"good", "great", "excellent", "happy", "love"};
    char *negative_words[] = {"bad", "terrible", "worst", "sad", "hate"};

    // Loop through each word in the text
    char *word = strtok(text, " ");
    while (word != NULL) {

        // Convert each word to lowercase for comparison
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is positive, negative, or neutral
        int is_positive = 0;
        int is_negative = 0;
        for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                is_positive = 1;
                break;
            }
        }
        for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
            if (strcmp(word, negative_words[i]) == 0) {
                is_negative = 1;
                break;
            }
        }
        if (!is_positive && !is_negative) {
            result.neutral++;
        } else if (is_positive) {
            result.positive++;
        } else {
            result.negative++;
        }

        word = strtok(NULL, " ");
    }

    return result;
}

int main() {
    // Test the sentiment analysis function with sample text
    char text[] = "I had a terrible day today, but the food was excellent!";
    SentimentResult result = analyze_sentiment(text);
    printf("Positive: %d\n", result.positive);
    printf("Negative: %d\n", result.negative);
    printf("Neutral: %d\n", result.neutral);

    return 0;
}