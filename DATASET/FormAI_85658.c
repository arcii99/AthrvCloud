//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: careful
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char positive_words[10][50] = {"happy", "excited", "good", "great", "love", "awesome", "fantastic", "terrific", "nice", "perfect"};
    char negative_words[10][50] = {"sad", "angry", "bad", "terrible", "hate", "awful", "horrible", "disappointing", "poor", "unhappy"};
    int positive_count = 0, negative_count = 0, neutral_count = 0;

    printf("Enter your text: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \n"); // split input string into words using spaces and newline character as separator

    while (token != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_count++;
            } else if (strcmp(token, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        token = strtok(NULL, " \n"); // move to the next word
    }

    if (positive_count > negative_count) {
        printf("The text has a positive sentiment.\n");
    } else if (positive_count < negative_count) {
        printf("The text has a negative sentiment.\n");
    } else {
        printf("The text has a neutral sentiment.\n");
    }

    return 0;
}