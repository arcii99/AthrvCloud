//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
/* A Romeo and Juliet-themed Intrusion Detection System */

#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int i, flag = 0;

    printf("Oh Romeo, Romeo, wherefore art thou Romeo?\n");

    scanf("%s", message);

    printf("It is the east, and Juliet is the sun.\n");

    for(i = 0; i < strlen(message); i++)
    {
        if(message[i] == 'e')
        {
            flag = 1;
        }
    }

    if(flag == 1)
    {
        printf("Aha! An intrusion attempt has been detected.\n");
    }
    else
    {
        printf("No intrusion attempt detected.\n");
    }

    printf("Goodnight, goodnight! Parting is such sweet sorrow, That I shall say good night till it be morrow.\n");

    return 0;
}