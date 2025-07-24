//FormAI DATASET v1.0 Category: Spam Detection System ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_MESSAGE_LENGTH 100

char spamWords[MAX_SPAM_WORDS][20] = {"buy", "discount", "free", "gift", "limited"};

int isSpam(char *message)
{
    char *word = strtok(message, " ");
    while (word != NULL)
    {
        for (int i = 0; i < MAX_SPAM_WORDS; i++)
        {
            if (strcmp(word, spamWords[i]) == 0)
            {
                return 1;
            }
        }
        word = strtok(NULL, " ");
    }
    return 0;
}

int main()
{
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    if (isSpam(message))
    {
        printf("Spam detected!\n");
    }
    else
    {
        printf("Not a spam message.\n");
    }

    return 0;
}