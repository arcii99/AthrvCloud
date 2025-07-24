//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <string.h>

// function to perform sentiment analysis
int sentiment_analysis(char* sentence) {
    int positive_words = 0;
    int negative_words = 0;
    char* positive[] = {"good", "great", "awesome", "fantastic", "excellent"};
    char* negative[] = {"bad", "terrible", "horrible", "awful", "poor"};

    // loop through each word in the sentence
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        // check if the word is a positive or negative word
        int i;
        for (i = 0; i < 5; i++) {
            if (strcmp(word, positive[i]) == 0) {
                positive_words++;
            } else if (strcmp(word, negative[i]) == 0) {
                negative_words++;
            }
        }

        // move to the next word in the sentence
        word = strtok(NULL, " ");
    }

    // determine sentiment score
    int score = positive_words - negative_words;
    return score;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // perform sentiment analysis on the sentence
    int score = sentiment_analysis(sentence);

    // output sentiment score
    printf("Sentiment score: %d\n", score);

    return 0;
}