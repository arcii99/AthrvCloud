//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>

int main()
{
    //define spam words
    char spamWords[5][10] = {"money", "offer", "fake", "free", "click"};
    char message[100];

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    //convert message to lowercase for easy comparison
    for(int i = 0; message[i]; i++)
    {
        message[i] = tolower(message[i]);
    }

    //check if message contains spam words
    int spamCount = 0;
    for(int i = 0; i < 5; i++)
    {
        if(strstr(message, spamWords[i]) != NULL)
        {
            spamCount++;
        }
    }

    if(spamCount > 0)
    {
        printf("This message contains spam.\n");
    }
    else
    {
        printf("This message is not spam.\n");
    }

    return 0;
}