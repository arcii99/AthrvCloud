//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char statement[100];
    printf("Enter a statement to analyze: ");
    fgets(statement, sizeof(statement), stdin);

    int sentiment_score = 0;

    char positive_words[10][30] = {"love", "happy", "amazing", "great", "excited", "joy", "wonderful", "fantastic", "excellent", "awesome"};
    char negative_words[10][30] = {"hate", "sad", "disappointed", "depressed", "frustrated", "angry", "miserable", "terrible", "awful", "horrible"};

    char *word = strtok(statement, " ");

    while (word != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(word, positive_words[i]) == 0)
            {
                sentiment_score++;
            }
            else if (strcmp(word, negative_words[i]) == 0)
            {
                sentiment_score--;
            }
        }
        word = strtok(NULL, " ");
    }

    printf("\nSentiment score: %d\n", sentiment_score);

    if (sentiment_score > 0)
    {
        printf("\nPositive sentiment! :)");
    }
    else if (sentiment_score < 0)
    {
        printf("\nNegative sentiment! :(");
    }
    else
    {
        printf("\nNeutral sentiment.");
    }

    return 0;
}