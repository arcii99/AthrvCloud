//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include<stdio.h>
#include<string.h>

int main(){
    char sentence[100];
    int pos_count = 0, neg_count = 0, neu_count = 0;
    float sentiment_score;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // convert to lowercase
    for(int i = 0; sentence[i]; i++){
        sentence[i] = tolower(sentence[i]);
    }

    // sentiment analysis
    char delim[] = " ,.\n";
    char *word = strtok(sentence, delim);
    while(word != NULL){
        if(strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0){
            pos_count++;
        }
        else if(strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "terrible") == 0){
            neg_count++;
        }
        else{
            neu_count++;
        }
        word = strtok(NULL, delim);
    }

    // calculate sentiment score
    sentiment_score = (float)(pos_count - neg_count) / (float)(pos_count + neg_count + neu_count);

    // output
    printf("\nSentiment Analysis:\n");
    printf("--------------------\n");
    printf("Positive words count: %d\n", pos_count);
    printf("Negative words count: %d\n", neg_count);
    printf("Neutral words count: %d\n", neu_count);
    if(sentiment_score > 0){
        printf("Sentiment score: %.2f (positive)", sentiment_score);
    }
    else if(sentiment_score < 0){
        printf("Sentiment score: %.2f (negative)", sentiment_score);
    }
    else{
        printf("Sentiment score: %.2f (neutral)", sentiment_score);
    }

    return 0;
}