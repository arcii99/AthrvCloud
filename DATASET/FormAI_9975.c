//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[500];
    int posCount = 0, negCount = 0, neutralCount = 0;

    printf("Enter the text to analyze sentiments:\n");
    fgets(input, 500, stdin); // read the input from user

    char *token;
    char delimeters[6] = " ,_.";

    token = strtok(input, delimeters);
    while (token != NULL)
    {
        int len = strlen(token);

        if (len >= 3)
        {
            int i = 0, j = len - 1;

            while (i <= j)
            {
                if (token[i] == token[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    break;
                }
            }

            if (i > j)
            {
                posCount++; // palindrome word with positive sentiment
            }
            else
            {
                negCount++; // non-palindrome word with negative sentiment
            }
        }
        else
        {
            neutralCount++; // neutral words with less than 3 characters
        }

        token = strtok(NULL, delimeters);
    }

    if (posCount > negCount)
    {
        printf("Input text has Positive sentiment\n");
    }
    else if (posCount < negCount)
    {
        printf("Input text has Negative sentiment\n");
    }
    else
    {
        printf("Input text has Neutral sentiment\n");
    }

    return 0;
}