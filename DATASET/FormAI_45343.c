//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int positive_words = 0, negative_words = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    char *positive[] = {"happy", "good", "great", "excellent", "love", "awesome", "best", "fantastic", "terrific", "amazing"};
    char *negative[] = {"sad", "bad", "terrible", "awful", "hate", "worst", "poor", "disgusting", "miserable", "horrible"};

    char *word = strtok(sentence, " ");

    while (word != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positive[i]) == 0) {
                positive_words++;
                break;
            } else if (strcmp(word, negative[i]) == 0) {
                negative_words++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    if (positive_words > negative_words) {
        printf("\nPositive sentiment detected.\n");
    } else if (negative_words > positive_words) {
        printf("\nNegative sentiment detected.\n");
    } else {
        printf("\nNeutral sentiment detected.\n");
    }

    return 0;
}