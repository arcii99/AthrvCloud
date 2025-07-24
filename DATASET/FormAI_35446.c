//FormAI DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int spam_count = 0;

    while(1)
    {
        printf("Enter your message: ");
        memset(message, 0, sizeof(message));
        fgets(message, sizeof(message), stdin);

        if(strstr(message, "buy now") || strstr(message, "get rich quick") || strstr(message, "earn money fast"))
        {
            printf("Message is SPAM!\n");
            spam_count++;
        }
        else
        {
            printf("Message is not spam!\n");
        }

        if(spam_count >= 3)
        {
            printf("SPAM DETECTED! BLOCKING USER!\n");
            break;
        }
    }

    return 0;
}