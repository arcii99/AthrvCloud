//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int positiveWords = 0, negativeWords = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    char *positive[] = {"good", "great", "awesome", "fantastic", "excellent"};
    char *negative[] = {"bad", "terrible", "not good", "awful", "horrible"};

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positive[i]) == 0) {
                positiveWords++;
            }
            if (strcmp(token, negative[i]) == 0) {
                negativeWords++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (positiveWords > negativeWords) {
        printf("The sentence is positive.\n");
    } else if (negativeWords > positiveWords) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}