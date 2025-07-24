//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int positive_words_count = 0, negative_words_count = 0;

    printf("Enter sentence to analyze: ");
    fgets(sentence, 100, stdin);

    char *positive_words[] = {"good", "great", "excellent", "fantastic", "awesome", "superb"};
    char *negative_words[] = {"bad", "terrible", "awful", "horrible", "poor", "disappointing"};

    char *word = strtok(sentence, " ");

    while (word != NULL) {
        for (int i = 0; i < 6; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive_words_count++;
            }
            if (strcmp(word, negative_words[i]) == 0) {
                negative_words_count++;
            }
        }
        word = strtok(NULL, " ");
    }

    if (positive_words_count > negative_words_count) {
        printf("Overall sentiment: Positive\n");
    } else if (positive_words_count < negative_words_count) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }

    printf("Positive words count: %d\n", positive_words_count);
    printf("Negative words count: %d\n", negative_words_count);

    return 0;
}