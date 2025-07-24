//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    int positiveWordsCount = 0, negativeWordsCount = 0;

    printf("Enter your sentence for sentiment analysis: ");
    fgets(input, 100, stdin);

    char *words = strtok(input, " ");
    while (words != NULL)
    {
        int len = strlen(words);
        words[len - 1] = '\0'; // Removing the newline character
        
        if(strcmp(words, "happy") == 0 || strcmp(words, "joyful") == 0 || strcmp(words, "excited") == 0 || strcmp(words, "awesome") == 0 || strcmp(words, "amazing") == 0)
        {
            positiveWordsCount++;
        }
        else if(strcmp(words, "sad") == 0 || strcmp(words, "angry") == 0 || strcmp(words, "frustrated") == 0 || strcmp(words, "terrible") == 0 || strcmp(words, "worst") == 0)
        {
            negativeWordsCount++;
        }

        words = strtok(NULL, " ");
    }

    if(positiveWordsCount > negativeWordsCount)
    {
        printf("Wow! Your sentence has a positive sentiment. You must be feeling great!\n");
    }
    else if(positiveWordsCount == negativeWordsCount)
    {
        printf("Your sentence has some positive and negative words. It's a bit of a mixed bag.\n");
    }
    else
    {
        printf("Oops! Your sentence has a negative sentiment. Is everything okay? Cheer up!\n");
    }

    return 0;
}