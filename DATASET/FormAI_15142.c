//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    char *positive_words[] = {"good", "happy", "joyful", "excellent", "love", "great", "fantastic"};
    char *negative_words[] = {"bad", "sad", "angry", "horrible", "hate", "terrible", "dislike"};

    int positive_count = 0;
    int negative_count = 0;

    char *word = strtok(input, " ");

    while (word != NULL) {
        for (int i = 0; i < 7; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive_count++;
            }
            else if (strcmp(word, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        word = strtok(NULL, " ");
    }

    printf("Positive words count: %d\n", positive_count);
    printf("Negative words count: %d\n", negative_count);

    if (positive_count > negative_count) {
        printf("Overall sentiment: Positive\n");
    }
    else if (positive_count < negative_count) {
        printf("Overall sentiment: Negative\n");
    }
    else {
        printf("Overall sentiment: Neutral\n");
    }

    return 0;
}