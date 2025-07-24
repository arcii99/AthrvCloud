//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[100];
    int happy = 0, sad = 0;

    printf("Enter a sentence to analyse its sentiment:");
    fgets(sentence, 100, stdin);

    char *token = strtok(sentence, " ");
    while(token != NULL)
    {
        if(strcmp(token, "happy") == 0 || strcmp(token, "joyful") == 0 || strcmp(token, "good") == 0)
        {
            happy++;
        }
        else if(strcmp(token, "sad") == 0 || strcmp(token, "unhappy") == 0 || strcmp(token, "bad") == 0)
        {
            sad++;
        }

        token = strtok(NULL, " ");
    }

    if(happy > sad)
    {
        printf("The sentiment of the sentence is positive.");
    }
    else if(sad > happy)
    {
        printf("The sentiment of the sentence is negative.");
    }
    else
    {
        printf("The sentiment of the sentence is neutral.");
    }

    return 0;
}