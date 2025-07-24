//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    int positive_words = 0, negative_words = 0, neutral_words = 0;
    char positive[50][20] = {"good", "great", "excellent", "awesome", "fantastic"};
    char negative[50][20] = {"bad", "terrible", "poor", "awful", "disappointing"};

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // split the input into words
    char* word = strtok(input, " ");
    while (word != NULL) {

        // convert word to lowercase for comparison
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // check if positive word
        for (int i = 0; i < 5; i++) {
            if (strcmp(positive[i], word) == 0) {
                positive_words++;
                break;
            }
        }

        // check if negative word
        for (int i = 0; i < 5; i++) {
            if (strcmp(negative[i], word) == 0) {
                negative_words++;
                break;
            }
        }

        // count neutral words
        if (positive_words == 0 && negative_words == 0) {
            neutral_words++;
        }

        // get next word
        word = strtok(NULL, " ");
    }

    // determine sentiment based on counts
    if (positive_words > negative_words && positive_words > neutral_words) {
        printf("Sentiment: Positive\n");
    } else if (negative_words > positive_words && negative_words > neutral_words) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }

    return 0;
}