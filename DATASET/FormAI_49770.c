//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);

    int sentiment_score = 0;

    char *pos_words[10] = {"happy", "excited", "love", "great", "good", "amazing", "fantastic", "enjoy", "awesome", "excellent"};
    char *neg_words[10] = {"sad", "angry", "hate", "terrible", "bad", "dislike", "awful", "depressed", "upset", "frustrated"};

    for (int i = 0; i < 10; i++) {
        if (strstr(text, pos_words[i])) {
            sentiment_score++;
        }
        if (strstr(text, neg_words[i])) {
            sentiment_score--;
        }
    }

    printf("Sentiment score: %d\n", sentiment_score);

    if (sentiment_score > 0) {
        printf("Overall sentiment: Positive\n");
    } else if (sentiment_score < 0) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }

    return 0;
}