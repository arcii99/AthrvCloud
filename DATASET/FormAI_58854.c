//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    int i, j, flag;

    printf("Enter your message: ");
    fgets(input, 100, stdin);

    char spamWords[5][20] = {"free", "offer", "deal", "limited time", "exclusive"};

    char *token = strtok(input, " \n");

    while (token != NULL)
    {
        flag = 0;
        
        for (j = 0; j < 5; j++)
        {
            if (strcasecmp(token, spamWords[j]) == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            printf("SPAM DETECTED: '%s'\n", token);
            printf("Please do not use spam words in your message!\n");
            exit(0);
        }

        token = strtok(NULL, " \n");
    }

    printf("Your message has been sent successfully!\n");
    return 0;
}