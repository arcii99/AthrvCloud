//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000];
    int spamWords = 0;
    char spamList[5][20] = {"buy", "discount", "offer", "cash", "limited time"};

    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    for(int i = 0; i < 5; i++)
    {
        if(strstr(message, spamList[i]) != NULL)
        {
            spamWords++;
        }
    }

    if(spamWords > 2)
    {
        printf("This message is spam.\n");
    }
    else 
    {
        printf("This message is not spam.\n");
    }

    return 0;
}