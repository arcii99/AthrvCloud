//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h> 

int main() 
{ 
    char sentence[100];
    int pos_count = 0, neg_count = 0, neutral_count = 0;
    float sentiment_score = 0.0;
    
    printf("Enter a sentence to analyze sentiment: ");
    fgets(sentence, 100, stdin);
    
    for(int i = 0; i < strlen(sentence); i++){
        if((sentence[i] == 'g' || sentence[i] == 'G') && (sentence[i+1] == 'o' || sentence[i+1] == 'O') && (sentence[i+2] == 'o' || sentence[i+2] == 'O') && (sentence[i+3] == 'd' || sentence[i+3] == 'D')){
            sentiment_score += 0.5;
            pos_count++;
            i+=3;
        } else if((sentence[i] == 'g' || sentence[i] == 'G') && (sentence[i+1] == 'r' || sentence[i+1] == 'R') && (sentence[i+2] == 'e' || sentence[i+2] == 'E') && (sentence[i+3] == 'a' || sentence[i+3] == 'A') && (sentence[i+4] == 't' || sentence[i+4] == 'T')){
            sentiment_score += 0.75;
            pos_count++;
            i+=4;
        } else if((sentence[i] == 'a' || sentence[i] == 'A') && (sentence[i+1] == 'w' || sentence[i+1] == 'W') && (sentence[i+2] == 'e' || sentence[i+2] == 'E') && (sentence[i+3] == 's' || sentence[i+3] == 'S') && (sentence[i+4] == 'o' || sentence[i+4] == 'O') && (sentence[i+5] == 'm' || sentence[i+5] == 'M') && (sentence[i+6] == 'e' || sentence[i+6] == 'E')){
            sentiment_score += 1.0;
            pos_count++;
            i+=6;
        } else if((sentence[i] == 'b' || sentence[i] == 'B') && (sentence[i+1] == 'a' || sentence[i+1] == 'A') && (sentence[i+2] == 'd' || sentence[i+2] == 'D')){
            sentiment_score -= 0.5;
            neg_count++;
            i+=2;
        } else if((sentence[i] == 'w' || sentence[i] == 'W') && (sentence[i+1] == 'o' || sentence[i+1] == 'O') && (sentence[i+2] == 'r' || sentence[i+2] == 'R') && (sentence[i+3] == 's' || sentence[i+3] == 'S') && (sentence[i+4] == 't' || sentence[i+4] == 'T')){
            sentiment_score -= 0.75;
            neg_count++;
            i+=4;
        } else if((sentence[i] == 't' || sentence[i] == 'T') && (sentence[i+1] == 'e' || sentence[i+1] == 'E') && (sentence[i+2] == 'r' || sentence[i+2] == 'R') && (sentence[i+3] == 'r' || sentence[i+3] == 'R') && (sentence[i+4] == 'i' || sentence[i+4] == 'I') && (sentence[i+5] == 'b' || sentence[i+5] == 'B') && (sentence[i+6] == 'l' || sentence[i+6] == 'L') && (sentence[i+7] == 'e' || sentence[i+7] == 'E')){
            sentiment_score -= 1.0;
            neg_count++;
            i+=7;
        } else {
            neutral_count++;
        }
    }

    printf("\nNumber of positive words: %d", pos_count);
    printf("\nNumber of negative words: %d", neg_count);
    printf("\nNumber of neutral words: %d", neutral_count);
    printf("\nSentiment score: %f\n", sentiment_score);
    
    if(sentiment_score > 0){
        printf("Overall sentiment is positive.");
    } else if(sentiment_score == 0){
        printf("Overall sentiment is neutral.");
    } else {
        printf("Overall sentiment is negative.");
    }

    return 0; 
}