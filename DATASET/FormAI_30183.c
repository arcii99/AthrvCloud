//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sentiment_analysis(char* text) {
    /* List of positive and negative words (can be expanded) */
    char *positive_words[] = {"good", "happy", "love", "great", "awesome", "excellent"};
    char *negative_words[] = {"bad", "sad", "hate", "terrible", "awful", "horrible"};
    
    int pos_count = 0, neg_count = 0;
    double sentiment_score = 0.0;
    char *token;

    /* Breaking down the string into individual words */
    token = strtok(text, " ");

    /* Calculating sentiment score for each word in text */
    while (token != NULL) {

        /* Checking if the word is found in positive_words */
        for (int i = 0; i < sizeof(positive_words)/sizeof(positive_words[0]); i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                sentiment_score += 1.0;
                pos_count++;
            }
        }

        /* Checking if the word is found in negative_words */
        for (int i = 0; i < sizeof(negative_words)/sizeof(negative_words[0]); i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                sentiment_score -= 1.0;
                neg_count++;
            }
        }

        /* Moving onto the next word*/
        token = strtok(NULL, " ");
    }

    /* Calculating the overall sentiment score of the text */
    sentiment_score /= (pos_count + neg_count);

    /* Checking if the text is overall positive, negative or neutral */
    if (sentiment_score > 0) {
        return 1; // positive
    } else if (sentiment_score < 0) {
        return -1; // negative
    } else {
        return 0; // neutral
    }
}

int main() {

    /* Testing the sentiment_analysis function */
    char text[] = "I am so happy and grateful for all the good in my life!";
    int sentiment = sentiment_analysis(text);

    /* Outputting the sentiment score */
    printf("Sentiment analysis result: %d", sentiment);

    return 0;
}