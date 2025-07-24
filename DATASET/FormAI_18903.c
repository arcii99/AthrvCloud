//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include<stdio.h>
#include<string.h>

#define MAX_INPUT_LENGTH 1000

int main()
{
    char input[MAX_INPUT_LENGTH];
    int sentiment_score = 0;
    int positive_words_count = 0;
    int negative_words_count = 0;
    
    // Positive words list
    char positive_words[][20]={
        "love",
        "happy",
        "good",
        "great",
        "excellent",
        "awesome",
        "fantastic",
        "amazing",
        "peaceful",
        "calm"
    };
    
    // Negative words list
    char negative_words[][20]={
        "hate",
        "sad",
        "bad",
        "terrible",
        "awful",
        "horrible",
        "disgusting",
        "unhappy",
        "upset",
        "angry"
    };
    
    printf("Enter the text to be analyzed (max %d characters): ", MAX_INPUT_LENGTH-1);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Removing the newline at the end of text
    input[strcspn(input, "\n")] = '\0';
    
    // Tokenizing input by space
    char *token;
    token = strtok(input, " ");
    while( token != NULL ) {
        // Checking for Positive words
        for(int i=0; i<10; i++){
            if(strcmp(token, positive_words[i]) == 0){
                sentiment_score += 1;
                positive_words_count += 1;
            }
        }
        // Checking for Negative words
        for(int i=0; i<10; i++){
            if(strcmp(token, negative_words[i]) == 0){
                sentiment_score -= 1;
                negative_words_count += 1;
            }
        }
        token = strtok(NULL, " ");
    }
    
    printf("\nSentiment score: %d\n", sentiment_score);
    
    if(sentiment_score > 0){
        printf("This is a positive text with %d positive words and %d negative words.\n", positive_words_count, negative_words_count);
    }else if(sentiment_score < 0){
        printf("This is a negative text with %d positive words and %d negative words.\n", positive_words_count, negative_words_count);
    }else{
        printf("This is a neutral text with %d positive words and %d negative words.\n", positive_words_count, negative_words_count);
    }
    
    return 0;
}