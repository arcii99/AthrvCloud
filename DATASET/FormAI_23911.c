//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    int positiveCount = 0;
    int negativeCount = 0;

    printf("Enter your text: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input

    char *token = strtok(input, " ");

    while (token != NULL) {
        if (strstr(token, "good") != NULL || strstr(token, "great") != NULL || strstr(token, "excellent") != NULL) {
            positiveCount++;
        }
        else if (strstr(token, "bad") != NULL || strstr(token, "terrible") != NULL || strstr(token, "awful") != NULL) {
            negativeCount++;
        }

        token = strtok(NULL, " ");
    }

    printf("Positive count: %d\n", positiveCount);
    printf("Negative count: %d\n", negativeCount);

    if (positiveCount > negativeCount) {
        printf("Sentiment: Positive\n");
    }
    else if (positiveCount < negativeCount) {
        printf("Sentiment: Negative\n");
    }
    else {
        printf("Sentiment: Neutral\n");
    }

    return 0;
}