//FormAI DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Welcome to the Spam Detection System!");
    printf("\nEnter the message to check for spam: ");

    char message[500];
    fgets(message, 500, stdin);
    message[strcspn(message, "\n")] = 0;

    int len = strlen(message);
    int count = 0;

    for(int i=0;i<len;i++)
    {
        if(message[i] == 's' && message[i+1] == 'p' && message[i+2] == 'a' && message[i+3] == 'm')
        {
            count++;
        }
    }

    if(count>0)
    {
        printf("\nSPAM DETECTED!!!");
    }
    else
    {
        printf("\nYour message is safe and free of spam!");
    }

    return 0;
}