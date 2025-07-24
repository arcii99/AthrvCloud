//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[1000];
    int positive_count = 0, negative_count = 0, neutral_count = 0;
    float sentiment_score;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    char *words = strtok(sentence, " ");

    while (words != NULL)
    {
        if (strstr(words, "good") != NULL || strstr(words, "great") != NULL || strstr(words, "excellent") != NULL)
        {
            positive_count++;
        }
        else if (strstr(words, "bad") != NULL || strstr(words, "terrible") != NULL || strstr(words, "awful") != NULL)
        {
            negative_count++;
        }
        else
        {
            neutral_count++;
        }
        words = strtok(NULL, " ");
    }

    printf("\nPositive words count: %d\n", positive_count);
    printf("Negative words count: %d\n", negative_count);
    printf("Neutral words count: %d\n", neutral_count);

    sentiment_score = (((float)positive_count - (float)negative_count) / ((float)positive_count + (float)negative_count + (float)neutral_count)) * 100;

    printf("\nSentiment Score: %.2f\n", sentiment_score);

    if (sentiment_score > 75)
    {
        printf("The sentiment of the sentence is very positive!\n");
    }
    else if (sentiment_score > 50)
    {
        printf("The sentiment of the sentence is positive.\n");
    }
    else if (sentiment_score > 25)
    {
        printf("The sentiment of the sentence is slightly positive.\n");
    }
    else if (sentiment_score > -25)
    {
        printf("The sentiment of the sentence is neutral.\n");
    }
    else if (sentiment_score > -50)
    {
        printf("The sentiment of the sentence is slightly negative.\n");
    }
    else if (sentiment_score > -75)
    {
        printf("The sentiment of the sentence is negative.\n");
    }
    else
    {
        printf("The sentiment of the sentence is very negative!\n");
    }

    return 0;
}