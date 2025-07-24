//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int positive;
    int negative;
    int neutral;
} Sentiment;

Sentiment analyzeSentiment(char *text) {
    Sentiment result = { 0, 0, 0 };

    char *positiveWords[] = { "happy", "love", "beautiful", "amazing" };
    char *negativeWords[] = { "sad", "hate", "ugly", "terrible" };

    char *token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < sizeof(positiveWords) / sizeof(char *); i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                result.positive++;
                break;
            }
        }
        for (int i = 0; i < sizeof(negativeWords) / sizeof(char *); i++) {
            if (strcmp(token, negativeWords[i]) == 0) {
                result.negative++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    result.neutral = strlen(text) - result.positive - result.negative;

    return result;
}

int main() {
    char text[1000];
    printf("Enter text to analyze sentiment: ");
    fgets(text, sizeof(text), stdin);
    Sentiment sentiment = analyzeSentiment(text);
    printf("Positive: %d\nNegative: %d\nNeutral: %d\n", sentiment.positive, sentiment.negative, sentiment.neutral);
    return 0;
}