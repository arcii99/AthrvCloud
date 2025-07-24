//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <string.h>

void analyzeSentiment(char *str);

int main()
{
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);
    analyzeSentiment(input);
    return 0;
}

void analyzeSentiment(char *str)
{
    int sentimentScore = 0;
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        if (strcmp(token, "good") == 0)
            sentimentScore++;
        else if (strcmp(token, "bad") == 0)
            sentimentScore--;
        token = strtok(NULL, " ");
    }

    if (sentimentScore > 0)
        printf("The sentiment of the sentence is positive\n");
    else if (sentimentScore < 0)
        printf("The sentiment of the sentence is negative\n");
    else
        printf("The sentiment of the sentence is neutral\n");
}