//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int positive = 0, negative = 0, neutral = 0;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    strtok(input, "\n");

    char *words = strtok(input, " ");

    while(words != NULL) {
        if(strcmp(words, "good") == 0 || strcmp(words, "great") == 0 || strcmp(words, "excellent") == 0) {
            positive++;
        } else if(strcmp(words, "bad") == 0 || strcmp(words, "terrible") == 0 || strcmp(words, "awful") == 0) {
            negative++;
        } else {
            neutral++;
        }
        words = strtok(NULL, " ");
    }

    printf("The sentiment analysis for the sentence is:\n");
    printf("Positive: %d\n", positive);
    printf("Negative: %d\n", negative);
    printf("Neutral: %d\n", neutral);

    return 0;
}