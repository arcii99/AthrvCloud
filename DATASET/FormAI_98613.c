//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include<stdio.h>
#include<string.h>

int main(void)
{
    char input[100];
    int joy = 0, sadness = 0, anger = 0, fear = 0;
    
    printf("Welcome to my unique sentiment analysis tool! Type some text and I'll tell you how you're feeling today.\n\n");
    
    while(1)
    {
        printf("Your text: ");
        fgets(input, 100, stdin);
        
        //Check if user wants to exit
        if(strcmp(input, "exit\n") == 0){
            printf("\nThanks for trying out my tool! Bye!\n");
            break;
        }
        
        //Check for emotions
        if(strstr(input, "LOL") != NULL || strstr(input, "lmao") != NULL){
            joy += 1;
        }
        if(strstr(input, "sad") != NULL || strstr(input, "cry") != NULL){
            sadness += 1;
        }
        if(strstr(input, "hate") != NULL || strstr(input, "mad") != NULL){
            anger += 1;
        }
        if(strstr(input, "scared") != NULL || strstr(input, "nervous") != NULL){
            fear += 1;
        }
        
        //Output sentiment analysis
        printf("\nSentiment Analysis:\n");
        printf("Joy: %d\n", joy);
        printf("Sadness: %d\n", sadness);
        printf("Anger: %d\n", anger);
        printf("Fear: %d\n\n", fear);
    }
    
    return 0;
}