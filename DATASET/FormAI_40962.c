//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
    char review[1000];
    char positive_words[5][20] = {"good", "great", "awesome", "excellent", "fantastic"};
    char negative_words[5][20] = {"bad", "poor", "terrible", "awful", "horrible"};
    int score = 0;

    printf("Enter your review: ");
    fgets(review, 1000, stdin);

    char* token = strtok(review, " ");
    while (token != NULL) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                score++;
            }
            if (strcmp(token, negative_words[i]) == 0) {
                score--;
            }
        }
        token = strtok(NULL, " ");
    }

    if (score > 0) {
        printf("Positive sentiment detected.\n");
    } else if (score < 0) {
        printf("Negative sentiment detected.\n");
    } else {
        printf("Neutral sentiment detected.\n");
    }

    return 0;
}