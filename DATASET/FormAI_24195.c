//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
/*
Author: Ada Lovelace

Program: Spam Detection System

Description: This program detects spam messages based on pre-defined rules.

*/

#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int i;
    int count = 0;

    printf("Enter the message to check for spam: ");
    fgets(input, 1000, stdin);

    // Rule 1: Check for excessive use of exclamation marks
    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] == '!')
        {
            count++;
        }
    }

    if(count > 5)
    {
        printf("Excessive use of exclamation marks detected. This is likely a spam message.\n");
        return 0;
    }

    // Rule 2: Check for suspicious keywords
    char keywords[5][20] = {"cash", "free", "money", "offer", "prize"};

    for(i = 0; i < 5; i++)
    {
        if(strstr(input, keywords[i]) != NULL)
        {
            printf("Suspicious keyword \"%s\" detected. This is likely a spam message.\n", keywords[i]);
            return 0;
        }
    }

    // If none of the rules are triggered, the message is likely not spam
    printf("This message is likely not spam.\n");

    return 0;
}