//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    int positive_score = 0, negative_score = 0, neutral_score = 0;
    
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    
    char *token = strtok(sentence, " ");
    
    while(token != NULL)
    {
        if(strstr(token, "good") || strstr(token, "great") || strstr(token, "excellent"))
        {
            positive_score++;
        }
        else if(strstr(token, "bad") || strstr(token, "horrible") || strstr(token, "terrible"))
        {
            negative_score++;
        }
        else
        {
            neutral_score++;
        }
        
        token = strtok(NULL, " ");
    }
    
    if(positive_score > negative_score && positive_score > neutral_score)
    {
        printf("The sentence has a positive sentiment.\n");
    }
    else if(negative_score > positive_score && negative_score > neutral_score)
    {
        printf("The sentence has a negative sentiment.\n");
    }
    else
    {
        printf("The sentence has a neutral sentiment.\n");
    }
    
    return 0;
}