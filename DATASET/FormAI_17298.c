//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <string.h>

int main(){

    char input[100];
    int score = 0;

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter your sentence:\n");
    scanf("%[^\n]", input);

    //Converting input to lowercase
    for (int i=0; i<strlen(input); i++){
        if(input[i]>='A' && input[i]<='Z'){
            input[i] += 32;
        }
    }

    //Analyzing the input sentence
    if(strstr(input, "happy") || strstr(input, "great") || strstr(input, "awesome")){
        score = 10;
    }
    else if(strstr(input, "sad") || strstr(input, "miserable") || strstr(input, "terrible")){
        score = -10;
    }
    else if(strstr(input, "love") || strstr(input, "kiss")){
        score = 5;
    }
    else if(strstr(input, "hate") || strstr(input, "kill")){
        score = -5;
    }
    else{
        score = 0;
    }

    //Printing the result
    if(score > 0){
        printf("Your sentence has a positive sentiment with a score of %d\n", score);
    }
    else if(score < 0){
        printf("Your sentence has a negative sentiment with a score of %d\n", score);
    }
    else{
        printf("Your sentence is neutral with a score of %d\n", score);
    }

    return 0;
}