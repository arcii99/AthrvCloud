//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
#include <stdio.h>
#include <string.h>

// Function to calculate sentiment score
int calculate_sentiment(char sentence[]) {
    int sentiment_score = 0;
    int words_count = 0;
    char *word = strtok(sentence, " .?!");

    while (word != NULL) {
        words_count++;

        if (strstr(word, "good") != NULL || strstr(word, "great") != NULL || strstr(word, "excellent") != NULL) {
            sentiment_score += 2;
        } else if (strstr(word, "bad") != NULL || strstr(word, "terrible") != NULL || strstr(word, "awful") != NULL) {
            sentiment_score -= 2;
        } else {
            sentiment_score += 1;
        }

        word = strtok(NULL, " .?!");
    }

    // If the number of words exceeds 10 or the sentiment score is less than or equal to -5, set paranoia flag
    if (words_count > 10 || sentiment_score <= -5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence to calculate sentiment: ");
    fgets(sentence, sizeof(sentence), stdin);

    int result = calculate_sentiment(sentence);

    if (result == 1) {
        printf("Paranoid sentiment detected, proceed with caution!\n");
    } else {
        printf("Sentiment is normal, carry on.\n");
    }

    return 0;
}