//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char input[100]; //To store user input
    int positive = 0, negative = 0, neutral = 0; //Variables to keep count of the sentiment
    printf("Enter your sentence: ");
    fgets(input, sizeof(input), stdin); //Taking user input
    
    char *words = strtok(input, " "); //Tokenizing the input string
    while(words != NULL)
    {
        if(strcmp(words, "good") == 0 || strcmp(words, "happy") == 0 || strcmp(words, "joy") == 0 || strcmp(words, "great") == 0)
            positive++; //Counting positive words
        else if(strcmp(words, "bad") == 0 || strcmp(words, "sad") == 0 || strcmp(words, "unhappy") == 0 || strcmp(words, "poor") == 0)
            negative++; //Counting negative words
        else
            neutral++; //Counting neutral words
        
        words = strtok(NULL, " "); //Continuing tokenization
    }
    
    printf("\nSentiment Analysis Result:\n");
    if(positive > negative)
        printf("Overall Sentiment is Positive.\n");
    else if(negative > positive)
        printf("Overall Sentiment is Negative.\n");
    else
        printf("Overall Sentiment is Neutral.\n");
    
    printf("\nPositive Words: %d", positive);
    printf("\nNegative Words: %d", negative);
    printf("\nNeutral Words: %d", neutral);
    
    return 0;
}