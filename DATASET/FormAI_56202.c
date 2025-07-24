//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

typedef struct {
    int positive;
    int negative;
    int neutral;
} sentiment_analysis_result;

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter a text to analyze:\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    sentiment_analysis_result result = {0, 0, 0};

    char *positive_words[] = {"love", "happiness", "amazing"};
    char *negative_words[] = {"hate", "sadness", "disappointing"};
    
    char *token = strtok(text, " ");
    while (token != NULL) {
        for (int i=0; i<3; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                result.positive++;
            } else if (strcmp(token, negative_words[i]) == 0) {
                result.negative++;
            } else {
                result.neutral++;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("Sentiment analysis result:\n");
    printf("Positive words: %d\n", result.positive);
    printf("Negative words: %d\n", result.negative);
    printf("Neutral words: %d\n", result.neutral);

    return 0;
}