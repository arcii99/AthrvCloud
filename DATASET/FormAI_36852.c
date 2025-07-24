//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    int sentiment_score = 0;
    char *positive_words[] = {"happy", "excited", "great", "awesome", "love", "amazing", "fantastic", "good", "positive", "joy"};
    char *negative_words[] = {"sad", "angry", "disappointed", "bad", "terrible", "negative", "down", "hate", "depressed", "anxious"};

    printf("Welcome to the Sentiment Analysis Tool\n");
    printf("Enter your sentence here: ");

    fgets(input, 1000, stdin);

    //convert input to lowercase
    for(int i = 0; i < strlen(input); i++){
        input[i] = tolower(input[i]);
    }

    //check for positive words
    for(int i = 0; i < sizeof(positive_words) / sizeof(positive_words[0]); i++){
        if(strstr(input, positive_words[i]) != NULL){
            sentiment_score++;
        }
    }

    //check for negative words
    for(int i = 0; i < sizeof(negative_words) / sizeof(negative_words[0]); i++){
        if(strstr(input, negative_words[i]) != NULL){
            sentiment_score--;
        }
    }

    //determine overall sentiment
    if(sentiment_score > 0){
        printf("\nPositive sentiment detected with a score of %d", sentiment_score);
    } else if(sentiment_score == 0){
        printf("\nNeutral sentiment detected with a score of %d", sentiment_score);
    } else {
        printf("\nNegative sentiment detected with a score of %d", sentiment_score);
    }

    return 0;
}