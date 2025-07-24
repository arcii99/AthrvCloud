//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// function to calculate the sentiment score
int calc_sentiment_score(char *text) {
    int score = 0;
    char words[100][20] = {"good", "great", "excellent", "awesome", "happy", "joyful", "love", "admire"};
    int weights[8] = {3, 3, 3, 3, 2, 2, 4, 4};
    char *token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < 8; i++) {
            if (strcmp(words[i], token) == 0) {
                score += weights[i];
            }
        }
        token = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char input[100];
    printf("Enter text: ");
    fgets(input, 100, stdin);

    int score = calc_sentiment_score(input);

    printf("Sentiment Score: %d\n", score);

    if (score >= 10) {
        printf("Very Positive");
    } 
    else if (score >= 5) {
        printf("Positive");
    }
    else if (score >= 0) {
        printf("Neutral");
    }
    else {
        printf("Negative");
    }

    return 0;
}