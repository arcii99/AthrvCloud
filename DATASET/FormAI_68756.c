//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 1000
#define POSITIVE_WORDS {"love", "happy", "excited", "great", "awesome"}
#define NEGATIVE_WORDS {"hate", "sad", "angry", "frustrated", "disappointed"}

int main(){
    char sentence[MAX_SENTENCE_LENGTH];
    int positive_score = 0, negative_score = 0;
    char *positive_words[] = POSITIVE_WORDS;
    char *negative_words[] = NEGATIVE_WORDS;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove newline character from input
    if ((strlen(sentence) > 0) && (sentence[strlen (sentence) - 1] == '\n'))
        sentence[strlen (sentence) - 1] = '\0';

    // Tokenize sentence by space
    char *token = strtok(sentence, " ");
    while (token != NULL){
        // Check if token is a positive or negative word
        int i;
        for (i = 0; i < sizeof(positive_words)/sizeof(char*); i++){
            if (strcmp(token, positive_words[i]) == 0){
                positive_score++;
            }
        }
        for (i = 0; i < sizeof(negative_words)/sizeof(char*); i++){
            if (strcmp(token, negative_words[i]) == 0){
                negative_score++;
            }
        }
        token = strtok(NULL, " ");
    }

    // Calculate sentiment score
    int sentiment_score = positive_score - negative_score;

    // Print sentiment analysis result
    if (sentiment_score > 0){
        printf("Sentiment Score: %d - Positive Sentiment\n", sentiment_score);
    }
    else if (sentiment_score < 0){
        printf("Sentiment Score: %d - Negative Sentiment\n", sentiment_score);
    }
    else{
        printf("Sentiment Score: %d - Neutral Sentiment\n", sentiment_score);
    }

    return 0;
}