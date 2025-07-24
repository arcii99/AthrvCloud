//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analyze(char *message);

int main()
{
    char message[1000];
    printf("Enter a message: ");
    fgets(message, 1000, stdin);
    analyze(message);
    return 0;
}

void analyze(char *message)
{
    int happy_count = 0;
    int sad_count = 0;
    char *happy_words[] = {"happy", "joyful", "excited", "delighted", "thrilled", "ecstatic"};
    char *sad_words[] = {"sad", "upset", "disappointed", "depressed", "unhappy", "miserable"};

    char *word = strtok(message, " ");
    while (word != NULL)
    {
        for (int i = 0; i < 6; i++)
        {
            if (strcmp(word, happy_words[i]) == 0)
            {
                happy_count++;
            }
            if (strcmp(word, sad_words[i]) == 0)
            {
                sad_count++;
            }
        }
        word = strtok(NULL, " ");
    }

    if (happy_count > sad_count)
    {
        printf("The message has a positive sentiment.\n");
    }
    else if (sad_count > happy_count)
    {
        printf("The message has a negative sentiment.\n");
    }
    else
    {
        printf("The sentiment of the message is neutral.\n");
    }
}