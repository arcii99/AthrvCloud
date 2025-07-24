//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 1024
#define SCALE_FACTOR 100

int main(void) {
    char input[ARRAY_SIZE];
    char lower_input[ARRAY_SIZE];
    int positive_words = 0;
    int negative_words = 0;
    int total_score = 0;

    scanf("%[^\n]%*c", input); // reading input sentence

    // converting input sentence to lowercase
    for (int i = 0; i < strlen(input); i++) {
        lower_input[i] = tolower(input[i]);
    }

    char *positive_words_list[] = {"happy", "great", "love", "awesome", "fantastic", "excellent"};
    char *negative_words_list[] = {"sad", "bad", "hate", "disappoint", "worst", "terrible"};

    // calculating score for positive and negative words
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < 6; j++) {
            if (strstr(lower_input, positive_words_list[j])) {
                positive_words++;
                total_score++;
            }

            if (strstr(lower_input, negative_words_list[j])) {
                negative_words++;
                total_score--;
            }
        }
    }

    // calculating sentiment score
    int sentiment_score = total_score * SCALE_FACTOR / (positive_words + negative_words);

    // printing results
    if (sentiment_score > 50) {
        printf("Positive sentiment detected\n");
    } else if (sentiment_score < -50) {
        printf("Negative sentiment detected\n");
    } else {
        printf("Neutral sentiment detected\n");
    }
    printf("Positive words: %d\n", positive_words);
    printf("Negative words: %d\n", negative_words);
    printf("Total score: %d\n", total_score);
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}