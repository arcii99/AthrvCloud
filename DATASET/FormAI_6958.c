//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include<stdio.h>
#include<string.h>

int main(){
    char sentence[100];
    int positive = 0, negative = 0, neutral = 0;
    
    printf("Enter a sentence to analyze: ");
    gets(sentence);
    
    char *token = strtok(sentence, " ");
    
    while(token != NULL){
        if(strstr(token, "good") || strstr(token, "great") || strstr(token, "excellent")){
            positive++;
        }else if(strstr(token, "bad") || strstr(token, "terrible") || strstr(token, "awful")){
            negative++;
        }else{
            neutral++;
        }
        token = strtok(NULL, " ");
    }
    
    if((positive > negative) && (positive > neutral)){
        printf("The sentence is positive\n");
    }else if((negative > positive) && (negative > neutral)){
        printf("The sentence is negative\n");
    }else{
        printf("The sentence is neutral\n");
    }
    
    return 0;
}