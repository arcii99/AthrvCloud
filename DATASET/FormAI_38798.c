//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>

int main(){
    char sentiment[100];
    printf("Please enter your sentence: \n");
    fgets(sentiment, 100, stdin); //takes in user input
    int score = 0;
    for(int i=0; i<strlen(sentiment);i++){
        if (sentiment[i]=='happy'){
            score += 3;
        } else if(sentiment[i]=='sad'){
            score -= 2;
        } else if(sentiment[i]=='angry'){
            score -= 3;
        } else if(sentiment[i]=='excited'){
            score += 4;
        } else if(sentiment[i]=='disappointed'){
            score -= 2;
        } else if(sentiment[i]=='calm'){
            score += 1;
        } else {
            continue;
        }
    }
    
    if(score>0){
        printf("Overall, the sentence has a positive sentiment. \n");
    } else if(score<0){
        printf("Overall, the sentence has a negative sentiment. \n");
    } else {
        printf("Overall, the sentence has a neutral sentiment. \n");
    }
    
    return 0;
}