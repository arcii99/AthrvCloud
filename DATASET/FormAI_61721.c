//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char sentence[1000];
    int positive_count = 0, negative_count = 0, neutral_count = 0;
    
    printf("Enter a sentence: ");
    scanf("%[^\n]s", sentence);
    
    char *word = strtok(sentence, " ");
    
    while(word != NULL)
    {
        if(strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0 || strcmp(word, "love") == 0)
        {
            positive_count++;
        }
        else if(strcmp(word, "sad") == 0 || strcmp(word, "hate") == 0 || strcmp(word, "angry") == 0)
        {
            negative_count++;
        }
        else
        {
            neutral_count++;
        }
        
        word = strtok(NULL, " ");
    }
    
    if(positive_count > negative_count && positive_count > neutral_count)
    {
        printf("The sentence is positive.");
    }
    else if(negative_count > positive_count && negative_count > neutral_count)
    {
        printf("The sentence is negative.");
    }
    else
    {
        printf("The sentence is neutral.");
    }
    
    return 0;
}