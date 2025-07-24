//FormAI DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>

int main()
{
    char message[100];
    int count = 0;

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] == 'f' && message[i+1] == 'r' && message[i+2] == 'e' && message[i+3] == 'e')
        {
            count++;
            i += 3;
        }
    }

    if (count >= 3)
    {
        printf("This message is considered as SPAM, please try again later.\n");
    }
    else
    {
        printf("This message is not considered as SPAM. Thank you for your message.\n");
    }

    return 0;
}