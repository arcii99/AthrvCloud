//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main()
{
    char line[1000];
    int positiveCount = 0;
    int negativeCount = 0;
    int neutralCount = 0;

    FILE *fp = fopen("text.txt", "r"); // opening file in read mode

    if (fp == NULL)
    {
        printf("Failed to open text file.");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        int countPositive = 0;
        int countNegative = 0;

        char *token = strtok(line, " ");

        while (token != NULL)
        {
            if (strstr(token, "good") || strstr(token, "great") || strstr(token, "happy") || strstr(token, "amazing")) // checking for positive words
            {
                countPositive++;
            }
            else if (strstr(token, "bad") || strstr(token, "poor") || strstr(token, "sad") || strstr(token, "terrible")) // checking for negative words
            {
                countNegative++;
            }
            token = strtok(NULL, " ");
        }

        if (countPositive > countNegative)
        {
            positiveCount++;
        }
        else if (countNegative > countPositive)
        {
            negativeCount++;
        }
        else
        {
            neutralCount++;
        }
    }

    fclose(fp);

    printf("Positive lines: %d\nNegative lines: %d\nNeutral lines: %d\n", positiveCount, negativeCount, neutralCount);

    return 0;
}