//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

int main(void) {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int positive_count = 0;
    int negative_count = 0;
    int neutral_count = 0;
    int total_count = 0;

    char *ptr = strtok(sentence, " .,!?\n");

    while (ptr != NULL) {
        total_count++;

        if (strcmp(ptr, "good") == 0 || strcmp(ptr, "great") == 0 || strcmp(ptr, "awesome") == 0) {
            positive_count++;
        } else if (strcmp(ptr, "bad") == 0 || strcmp(ptr, "terrible") == 0 || strcmp(ptr, "awful") == 0) {
            negative_count++;
        } else {
            neutral_count++;
        }

        ptr = strtok(NULL, " .,!?\n");
    }

    if (total_count == 0) {
        printf("No words found in sentence.\n");
    } else {
        double positive_percentage = (double) positive_count / total_count * 100;
        double negative_percentage = (double) negative_count / total_count * 100;
        double neutral_percentage = (double) neutral_count / total_count * 100;

        printf("Positive words: %d (%.2f%%)\n", positive_count, positive_percentage);
        printf("Negative words: %d (%.2f%%)\n", negative_count, negative_percentage);
        printf("Neutral words: %d (%.2f%%)\n", neutral_count, neutral_percentage);

        if (positive_percentage > negative_percentage) {
            printf("Overall sentiment: Positive\n");
        } else if (negative_percentage > positive_percentage) {
            printf("Overall sentiment: Negative\n");
        } else {
            printf("Overall sentiment: Neutral\n");
        }
    }

    return 0;
}