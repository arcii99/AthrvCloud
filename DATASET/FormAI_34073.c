//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str[50];
    printf("Enter a sentence for sentiment analysis: ");
    fgets(str, 50, stdin);
    
    int sentiment = 0;
    char *word = strtok(str, " ");
    
    while(word != NULL)
    {
        if(strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0)
        {
            sentiment++;
        }
        else if(strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "terrible") == 0)
        {
            sentiment--;
        }
        word = strtok(NULL, " ");
    }
    
    if(sentiment > 0)
    {
        printf("The sentiment of the sentence is positive.");
    }
    else if(sentiment < 0)
    {
        printf("The sentiment of the sentence is negative.");
    }
    else
    {
        printf("The sentiment of the sentence is neutral.");
    }
    
    return 0;
}