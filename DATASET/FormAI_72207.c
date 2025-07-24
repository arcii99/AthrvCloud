//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include<stdio.h>
#include<string.h>

int main()
{
    char input[100];
    int i, flag = 0;

    printf("Enter the message: ");
    fgets(input, 100, stdin);

    char *spamWords[] = {"buy", "free", "discount", "limited", "offer", "money", "cash", "win", "won", "prize"};

    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] = input[i] + 32;
        }
    }

    for(i = 0; i < 10; i++)
    {
        if(strstr(input, spamWords[i]) != NULL)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        printf("\nSPAM detected! The message contains inappropriate words and phrases.\n");
    }
    else
    {
        printf("\nThe message is clean! No SPAM detected.\n");
    }

    return 0;
}