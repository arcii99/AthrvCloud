//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include<stdio.h>
#include<string.h>

//Function to calculate sentiment score
int calculateSentimentScore(char *input){
    int sentimentScore = 0;
    char *tokens = strtok(input, " ");
    while(tokens!=NULL){
        if(strcmp(tokens, "good")==0 || strcmp(tokens, "great")==0 || strcmp(tokens, "nice")==0){
            sentimentScore++;
        }else if(strcmp(tokens, "bad")==0 || strcmp(tokens, "worst")==0 || strcmp(tokens, "terrible")==0){
            sentimentScore--;
        }
        tokens = strtok(NULL, " ");
    }
    return sentimentScore;
}

int main(){
    char input[1000];
    printf("Enter the sentence to check sentiment score:\n");
    scanf("%[^\n]s", input);
    
    int sentimentScore = calculateSentimentScore(input);
    
    if(sentimentScore>0){
        printf("The sentiment score is positive. :)\n");
    }else if(sentimentScore<0){
        printf("The sentiment score is negative. :( \n");
    }else{
        printf("The sentiment score is neutral. :| \n");
    }
    return 0;   
}