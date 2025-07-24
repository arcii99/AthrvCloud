//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000

int main()
{
    char message[MAX_LEN];
    int spamCount = 0;

    printf("Enter a message: ");
    fgets(message, MAX_LEN, stdin);

    char *spamWords[] = {"buy", "on sale", "limited time only", "click here", "earn money fast"};

    for(int i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = message[i] + 32;
        }
    }

    char *word = strtok(message, " .,!?\n");

    while(word != NULL)
    {
        for(int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++)
        {
            if(strcmp(word, spamWords[i]) == 0)
            {
                spamCount++;
            }
        }
        word = strtok(NULL, " .,!?\n");
    }

    if(spamCount > 0)
    {
        printf("This message seems like spam");
    }
    else
    {
        printf("This message is not spam");
    }

    return 0;
}