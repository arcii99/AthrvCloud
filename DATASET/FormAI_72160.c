//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function that analyzes the sentiment of the input string
// returns 1 if the sentiment is positive, -1 if negative, 0 if neutral
int sentiment_analysis(char *input){

    char *positive_words[] = {"good", "great", "excellent", "happy", "love", "nice", "amazing"};
    char *negative_words[] = {"bad", "horrible", "terrible", "hate", "angry", "dislike", "awful"};

    // tokenize the input string
    char *word = strtok(input, " ");
    int pos_count = 0, neg_count = 0;

    while(word != NULL){
        // check if the current word is positive
        for(int i=0; i<7; i++){
            if(strcmp(word, positive_words[i]) == 0){
                pos_count++;
                break;
            }
        }

        // check if the current word is negative
        for(int i=0; i<7; i++){
            if(strcmp(word, negative_words[i]) == 0){
                neg_count++;
                break;
            }
        }

        word = strtok(NULL, " "); // move to the next word
    }

    // determine the sentiment based on the counts of positive and negative words
    if(pos_count > neg_count)
        return 1;
    else if(neg_count > pos_count)
        return -1;
    else
        return 0;
}

int main(){

    char input[100];
    int sentiment;

    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    sentiment = sentiment_analysis(input);

    if(sentiment == 1)
        printf("Positive sentiment detected!\n");
    else if(sentiment == -1)
        printf("Negative sentiment detected!\n");
    else
        printf("Neutral sentiment detected!\n");

    return 0;
}