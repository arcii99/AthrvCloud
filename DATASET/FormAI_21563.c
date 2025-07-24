//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

typedef enum {
    NEGATIVE,
    NEUTRAL,
    POSITIVE
} Sentiment;

Sentiment analyze_sentiment(char* input);

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    Sentiment sentiment = analyze_sentiment(input);
    switch(sentiment) {
        case NEGATIVE:
            printf("The input has a negative sentiment.\n");
            break;
        case NEUTRAL:
            printf("The input has a neutral sentiment.\n");
            break;
        case POSITIVE:
            printf("The input has a positive sentiment.\n");
            break;
    }
    return 0;
}

Sentiment analyze_sentiment(char* input) {
    int total_words = 1;
    int positive_words = 0;
    int negative_words = 0;
    char delimiter[] = " .,!?\n";
    char* token = strtok(input, delimiter);
    while(token != NULL) {
        if(strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0 || strcmp(token, "awesome") == 0) {
            positive_words++;
        } else if(strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0 || strcmp(token, "horrible") == 0) {
            negative_words++;
        }
        total_words++;
        token = strtok(NULL, delimiter);
    }
    float sentiment_percentage = (float)(positive_words - negative_words) / total_words * 100;
    if(sentiment_percentage < -10) {
        return NEGATIVE;
    } else if(sentiment_percentage > 10) {
        return POSITIVE;
    } else {
        return NEUTRAL;
    }
}