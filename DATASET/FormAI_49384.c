//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    printf("Enter your sentence: ");
    fgets(input, 1000, stdin);

    int positive = 0, negative = 0, neutral = 0;
    char *word = strtok(input, " ");

    while (word != NULL)
    {
        if (strstr(word, "good") != NULL || strstr(word, "happy") != NULL || strstr(word, "love") != NULL)
        {
            positive++;
        }
        else if (strstr(word, "bad") != NULL || strstr(word, "sad") != NULL || strstr(word, "hate") != NULL)
        {
            negative++;
        }
        else
        {
            neutral++;
        }

        word = strtok(NULL, " ");
    }

    printf("\nAnalysis Report:\n");
    printf("Positive words found: %d\nNegative words found: %d\nNeutral words found: %d\n", positive, negative, neutral);

    if (positive > negative)
    {
        printf("\nThe given sentence is more positive than negative.\n");
    }
    else if (negative > positive)
    {
        printf("\nThe given sentence is more negative than positive.\n");
    }
    else
    {
        printf("\nThe given sentence is neutral.\n");
    }

    return 0;
}