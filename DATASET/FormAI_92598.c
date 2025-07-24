//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store sentiment analysis values
typedef struct sentiment {
    float positive;
    float negative;
} sentiment_t;

// Define function to analyze sentiment of a string
sentiment_t analyze_sentiment(char * str) {
    sentiment_t s;
    s.positive = 0;
    s.negative = 0;

    // Sentiment analysis algorithm
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == 'good' || c == 'excellent' || c == 'great') {
            s.positive += 1;
        }
        else if (c == 'bad' || c == 'terrible' || c == 'awful') {
            s.negative += 1;
        }
    }

    // Normalize sentiment values
    float sum = s.positive + s.negative;
    if (sum > 0) {
        s.positive /= sum;
        s.negative /= sum;
    }

    return s;
}

int main() {
    char input[100];
    printf("Enter your statement: ");
    fgets(input, 100, stdin);

    sentiment_t sentiment = analyze_sentiment(input);
    printf("Positive sentiment: %.2f\n", sentiment.positive);
    printf("Negative sentiment: %.2f\n", sentiment.negative);

    return 0;
}