//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <string.h>

/* Function to calculate sentiment score of a sentence */
int calculateSentimentScore(char sentence[]) {
    int sentimentScore = 0;

    /* List of positive and negative words */
    char positiveWords[][20] = {"happy", "love", "like", "good", "great", "excellent"};
    char negativeWords[][20] = {"hate", "angry", "bad", "awful", "terrible", "dislike"};

    /* Calculate sentiment score of the sentence */
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        /* Check if word is positive */
        for (int i=0; i<6; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                sentimentScore += 1;
                break;
            }
        }

        /* Check if word is negative */
        for (int i=0; i<6; i++) {
            if (strcmp(word, negativeWords[i]) == 0) {
                sentimentScore -= 1;
                break;
            }
        }

        /* Get next word */
        word = strtok(NULL, " ");
    }

    return sentimentScore;
}

/* Main function */
int main() {
    char sentence[200];

    /* Get input sentence from user */
    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin);

    /* Calculate sentiment score */
    int score = calculateSentimentScore(sentence);

    /* Print sentiment analysis result */
    if (score > 0) {
        printf("Positive Sentiment\n");
    } else if (score < 0) {
        printf("Negative Sentiment\n");
    } else {
        printf("Neutral Sentiment\n");
    }

    return 0;
}