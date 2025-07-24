//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //initializing variables to store the input string and sentiment score
    char input[1000];
    int sentiment = 0;
    
    //get user input
    printf("Enter your text for sentiment analysis: ");
    fgets(input, 1000, stdin);
    
    //splitting the input string into individual words using strtok function
    char *token = strtok(input, " ");
    while(token != NULL)
    {
        //checking for positive words
        if(strcmp(token, "good")==0 || strcmp(token, "great")==0 || strcmp(token, "excellent")==0 || strcmp(token, "awesome")==0 || strcmp(token, "fantastic")==0)
        {
            sentiment += 1;
        }
        //checking for negative words
        else if(strcmp(token, "bad")==0 || strcmp(token, "poor")==0 || strcmp(token, "terrible")==0 || strcmp(token, "awful")==0 || strcmp(token, "horrible")==0)
        {
            sentiment -= 1;
        }
        //moving to next word
        token = strtok(NULL, " ");
    }
    
    //determining final sentiment score and outputting result
    if(sentiment > 0)
    {
        printf("Positive sentiment detected!\n");
    }
    else if(sentiment < 0)
    {
        printf("Negative sentiment detected!\n");
    }
    else
    {
        printf("Neutral sentiment detected.\n");
    }

    return 0;
}