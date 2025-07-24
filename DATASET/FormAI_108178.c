//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int spamChecker(char* message)
{
    char spamWords[6][15] = {"buy", "free", "discount", "click", "offer", "limited time"};
    int i, j, count;
    char tempMessage[MAX_LEN];
    strcpy(tempMessage, message);

    // Removing Punctuations
    for(i = 0; tempMessage[i] != '\0'; ++i)
    {
        while (!((tempMessage[i] >= 'a' && tempMessage[i] <= 'z') || (tempMessage[i] >= 'A' && tempMessage[i] <= 'Z') || tempMessage[i] == '\0'))
        {
            for(j = i; tempMessage[j] != '\0'; ++j)
            {
                tempMessage[j] = tempMessage[j+1];
            }
            tempMessage[j] = '\0';
        }
    }

    // Checking for Spam Words
    for(i = 0; i < 6; ++i)
    {
        count = 0;
        char* ptr = strstr(tempMessage, spamWords[i]);
        while(ptr != NULL)
        {
            count++;
            ptr = strstr(ptr+1, spamWords[i]);
        }

        if(count > 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char message[MAX_LEN];
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    if(spamChecker(message))
    {
        printf("Spam Detected!\n");
    }
    else
    {
        printf("No Spam Detected.\n");
    }

    return 0;
}