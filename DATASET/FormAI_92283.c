//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sentence[100], c;
    int i = 0, pos = 0, neg = 0, neu = 0;

    printf("Hello! I am the Sentiment Analysis AI. Please enter a sentence:\n");

    while ((c = getchar()) != '\n')
    {
        sentence[i++] = c;
    }
    sentence[i] = '\0';

    for (int j = 0; j < i; j++)
    {
        if (sentence[j] == 'h')
        {
            pos++;
        }
        else if (sentence[j] == 'm')
        {
            neu++;
        }
        else if (sentence[j] == 'x')
        {
            neg++;
        }
    }

    printf("The sentiment analysis results are in!\n\n");

    if (pos > neg)
    {
        printf("Your sentence is overwhelmingly positive.\n");
    }
    else if (neg > pos)
    {
        printf("Your sentence is overwhelmingly negative.\n");
    }
    else
    {
        printf("Your sentence is quite neutral.\n");
    }

    printf("\nThank you for using Sentiment Analysis AI! Goodbye!\n");

    return 0;
}