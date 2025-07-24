//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
 
int main()
{
    char text[1000];
    int positive = 0;
    int negative = 0;
    int neutral = 0;
 
    printf("Enter the text to be analyzed: ");
    fgets(text, 1000, stdin);
 
    char *words = strtok(text, " ");
 
    while (words != NULL)
    {
        if (strcasecmp(words, "good") == 0 || strcasecmp(words, "great") == 0 || strcasecmp(words, "excellent") == 0)
        {
            positive++;
        }
        else if (strcasecmp(words, "bad") == 0 || strcasecmp(words, "poor") == 0 || strcasecmp(words, "disappointing") == 0)
        {
            negative++;
        }
        else
        {
            neutral++;
        }
 
        words = strtok(NULL, " ");
    }
 
    printf("\nSentiment Analysis Result:\n");
    printf("Positive: %d\n", positive);
    printf("Negative: %d\n", negative);
    printf("Neutral: %d\n", neutral);
 
    if (positive > negative)
    {
        printf("\nThe text has a positive sentiment.\n");
    }
    else if (positive < negative)
    {
        printf("\nThe text has a negative sentiment.\n");
    }
    else
    {
        printf("\nThe text has a neutral sentiment.\n");
    }
 
    return 0;
}