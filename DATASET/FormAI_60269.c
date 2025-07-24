//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

int main(void) {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence to analyze: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int i, sentiment_score = 0;

    // Define a list of positive and negative words
    char* positive_words[] = {"good", "great", "excellent", "amazing", "happy", "fantastic"};
    char* negative_words[] = {"bad", "terrible", "awful", "poor", "miserable", "horrible"};

    // Tokenize the sentence
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        // Remove trailing newline character
        if (token[strlen(token) - 1] == '\n') {
            token[strlen(token) - 1] = '\0';
        }

        // Check if token is in positive or negative list
        for (i = 0; i < 6; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                sentiment_score++;
                break;
            } else if (strcmp(token, negative_words[i]) == 0) {
                sentiment_score--;
                break;
            }
        }

        // Get next token
        token = strtok(NULL, " ");
    }

    // Determine sentiment level based on score
    char* sentiment_level;
    if (sentiment_score > 0) {
        sentiment_level = "positive";
    } else if (sentiment_score < 0) {
        sentiment_level = "negative";
    } else {
        sentiment_level = "neutral";
    }

    printf("Sentiment score: %d\n", sentiment_score);
    printf("Sentiment level: %s\n", sentiment_level);

    return 0;
}