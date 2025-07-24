//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[1000];
    int positiveCount = 0, negativeCount = 0, neutralCount = 0;

    printf("Enter the text to be analyzed:");
    fgets(input, 1000, stdin);

    //converting all letters to lowercase
    for(int i=0;i<strlen(input);i++){
        if(input[i]>='A' && input[i]<='Z')
            input[i]+=32;
    }

    //splitting input string into words and analyzing each word
    char* token = strtok(input, " ");
    while(token != NULL){
        if(strcmp(token, "good")==0 || strcmp(token, "great")==0 || strcmp(token, "excellent")==0 || strcmp(token, "amazing")==0 || strcmp(token, "happy")==0 || strcmp(token, "love")==0)
            positiveCount++;
        else if(strcmp(token, "bad")==0 || strcmp(token, "poor")==0 || strcmp(token, "terrible")==0 || strcmp(token, "awful")==0 || strcmp(token, "sad")==0 || strcmp(token, "hate")==0)
            negativeCount++;
        else
            neutralCount++;
        token = strtok(NULL, " ");
    }

    printf("Sentiment analysis report:\n");
    printf("Total words analyzed: %d\n", positiveCount+negativeCount+neutralCount);
    printf("Positive words: %d\n", positiveCount);
    printf("Negative words: %d\n", negativeCount);
    printf("Neutral words: %d\n", neutralCount);

    if(positiveCount > negativeCount)
        printf("Overall sentiment is positive.");
    else if(negativeCount > positiveCount)
        printf("Overall sentiment is negative.");
    else
        printf("Overall sentiment is neutral.");

    return 0;
}