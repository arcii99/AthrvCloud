//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// function to calculate sentiment score
int calculateSentimentScore(char sentence[]) {
    char positiveWords[10][20] = {"good", "great", "awesome", "excellent", "fantastic", "superb", "amazing", "perfect", "wonderful", "phenomenal"};
    char negativeWords[10][20] = {"bad", "terrible", "awful", "horrible", "poor", "disappointing", "disaster", "regrettable", "unfortunate", "miserable"};
    int positiveScore = 0;
    int negativeScore = 0;

    // loop through each word in the sentence, check for positive and negative words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        for(int i = 0; i < 10; i++) {
            if(strcmp(token, positiveWords[i]) == 0) {
                positiveScore++;
            }
            if(strcmp(token, negativeWords[i]) == 0) {
                negativeScore--;
            }
        }
        token = strtok(NULL, " ");
    }

    // calculate overall sentiment score and return it
    int sentimentScore = positiveScore + negativeScore;
    return sentimentScore;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // remove the newline character from the end of the input
    sentence[strcspn(sentence, "\n")] = 0;

    // call calculateSentimentScore function and print the sentiment score
    int sentimentScore = calculateSentimentScore(sentence);
    printf("Sentiment score: %d\n", sentimentScore);

    return 0;
}