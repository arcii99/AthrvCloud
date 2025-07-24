//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter a sentence to perform sentiment analysis:\n");
    fgets(input, 1000, stdin);

    int positive_words_count = 0;
    int negative_words_count = 0;
    int neutral_words_count = 0;

    // Split the sentence into individual words
    char* word_ptr = strtok(input, " ");
    while (word_ptr != NULL) {
        // Check if the current word is positive
        char positive_words[10][10] = {
            "good",
            "awesome",
            "great",
            "fantastic",
            "excellent"
        };
        for (int i = 0; i < 5; i++) {
            if (strcmp(word_ptr, positive_words[i]) == 0) {
                positive_words_count++;
                break;
            }
        }

        // Check if the current word is negative
        char negative_words[10][10] = {
            "bad",
            "awful",
            "terrible",
            "poor",
            "horrible"
        };
        for (int i = 0; i < 5; i++) {
            if (strcmp(word_ptr, negative_words[i]) == 0) {
                negative_words_count++;
                break;
            }
        }

        // If the word is not positive or negative, consider it as neutral
        if (!strstr(positive_words[0], word_ptr) && !strstr(negative_words[0], word_ptr)) {
            neutral_words_count++;
        }

        word_ptr = strtok(NULL, " ");
    }

    // Determine the overall sentiment of the sentence
    printf("Positive words count: %d\n", positive_words_count);
    printf("Negative words count: %d\n", negative_words_count);
    printf("Neutral words count: %d\n", neutral_words_count);

    if (positive_words_count > negative_words_count) {
        printf("Overall sentiment of the sentence is positive.\n");
    } else if (positive_words_count < negative_words_count) {
        printf("Overall sentiment of the sentence is negative.\n");
    } else {
        printf("Overall sentiment of the sentence is neutral.\n");
    }

    return 0;
}