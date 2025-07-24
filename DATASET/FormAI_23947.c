//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include<stdio.h>
#include<string.h>

int main(){
    
    char sentence[50];
    int i=0, p_count=0, n_count=0,neu_count=0;
    
    printf("Welcome to the Cheerful Sentiment Analysis Tool!\n");
    printf("Please enter your sentence:\n");
    scanf("%[^\n]%*c", sentence); //taking input
    
    char *token = strtok(sentence, " "); //getting tokens of the input sentence
    
    while (token != NULL){
        if(strcmp(token, "happy")==0 || strcmp(token, "joyful")==0 || strcmp(token, "excited")==0){
            p_count++; //incrementing positive count for each positive word
        }
        else if(strcmp(token, "sad")==0 || strcmp(token, "depressed")==0 || strcmp(token, "anxious")==0){
            n_count++; //incrementing negative count for each negative word
        }
        else{
            neu_count++; //incrementing neutral count for each neutral word
        }
        token = strtok(NULL, " "); //getting next token
    }
    
    //determining overall sentiment based on count values
    if(p_count > n_count){
        printf("\nYour sentence is cheerful with a positive sentiment!\n");
    }
    else if(n_count > p_count){
        printf("\nYour sentence is gloomy with a negative sentiment!\n");
    }
    else{
        printf("\nYour sentence is neutral.\n");
    }
    
    //printing count values for each sentiment
    printf("\nPositive words count: %d\n", p_count);
    printf("Negative words count: %d\n", n_count);
    printf("Neutral words count: %d\n", neu_count);
    
    printf("\nThank you for using the Cheerful Sentiment Analysis Tool!\n");
    
    return 0;
}