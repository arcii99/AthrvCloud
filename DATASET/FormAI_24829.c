//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int positive_count = 0, negative_count = 0;

    printf("Enter your sentence: ");
    fgets(input, 100, stdin);

    char* word = strtok(input, " ");

    while (word != NULL) {
        if (strstr("good great happy nice", word)) {
            positive_count++;
        } else if (strstr("bad terrible sad awful", word)) {
            negative_count++;
        }
        word = strtok(NULL, " ");
    }

    int sentiment_score = positive_count - negative_count;

    if (sentiment_score > 0) {
        printf("Sentiment analysis: Positive\n");
    } else if (sentiment_score < 0) {
        printf("Sentiment analysis: Negative\n");
    } else {
        printf("Sentiment analysis: Neutral\n");
    }

    return 0;
}