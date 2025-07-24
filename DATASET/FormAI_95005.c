//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

int analyze_sentiment(char text[]);

int main() {
    char text[MAX_TEXT_LENGTH];
    
    printf("Enter some text to analyze sentiment:\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    int sentiment = analyze_sentiment(text);

    if (sentiment > 0) {
        printf("Positive sentiment detected!\n");
    } else if (sentiment < 0) {
        printf("Negative sentiment detected!\n");
    } else {
        printf("Neutral sentiment detected.\n");
    }

    return 0;
}

int analyze_sentiment(char text[]) {
    char *positive_words[] = {"good", "great", "amazing", "excellent", "happy"};
    char *negative_words[] = {"bad", "terrible", "awful", "poor", "sad"};
    int num_positive_words = sizeof positive_words / sizeof positive_words[0];
    int num_negative_words = sizeof negative_words / sizeof negative_words[0];
    char *token;
    int positive_count = 0;
    int negative_count = 0;

    // Get the first token
    token = strtok(text, " ,.-\n\r");

    while (token != NULL) {
        // Check if the token is a positive word
        for (int i = 0; i < num_positive_words; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_count++;
                break;
            }
        }

        // Check if the token is a negative word
        for (int i = 0; i < num_negative_words; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                negative_count++;
                break;
            }
        }

        // Get the next token
        token = strtok(NULL, " ,.-\n\r");
    }

    return positive_count - negative_count;
}