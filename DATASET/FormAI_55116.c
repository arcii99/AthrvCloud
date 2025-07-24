//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

int main() {

    char message[MAX_SIZE];

    // User Input
    printf("Enter a message: ");
    fgets(message, MAX_SIZE, stdin);

    // Sentiment Analysis
    char *positiveWords[] = {"happy", "love", "awesome", "great", "fantastic", "fun"};
    char *negativeWords[] = {"sad", "hate", "terrible", "horrible", "bad", "angry"};

    int positiveCount = 0;
    int negativeCount = 0;

    char *token = strtok(message, " .\n");
    while (token != NULL) {
        for (int i = 0; i < sizeof(positiveWords)/sizeof(positiveWords[0]); i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                positiveCount++;
            }
        }
        for (int i = 0; i < sizeof(negativeWords)/sizeof(negativeWords[0]); i++) {
            if (strcmp(token, negativeWords[i]) == 0) {
                negativeCount++;
            }
        }
        token = strtok(NULL, " .\n");
    }

    // Output Sentiment Results
    printf("Positive Words Found: %d\n", positiveCount);
    printf("Negative Words Found: %d\n", negativeCount);

    if (positiveCount > negativeCount) {
        printf("Overall Sentiment: Positive\n");
    } else if (negativeCount > positiveCount) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }

    return 0;
}