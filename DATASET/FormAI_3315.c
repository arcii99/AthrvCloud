//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
// Sentiment analysis tool for Romeo and Juliet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    const char *positive_words[] = {"love", "kiss", "hug", "joy", "happy"};
    const char *negative_words[] = {"hate", "pain", "sorrow", "death", "tears"};
    int positive_count = 0;
    int negative_count = 0;

    printf("Enter the text to analyze:\n");
    fgets(input, 1000, stdin);
    input[strlen(input) - 1] = '\0';

    char *token = strtok(input, " ");
    while (token != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(token, positive_words[i]) == 0)
            {
                positive_count++;
            }
            else if (strcmp(token, negative_words[i]) == 0)
            {
                negative_count++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (positive_count > negative_count)
        printf("It's a joyful message, my love!\n");
    else if (negative_count > positive_count)
        printf("Oh, my heart aches! The message is filled with sorrow!\n");
    else
        printf("The message is as neutral as the moon that hangs in yonder sky!\n");

    return 0;
}