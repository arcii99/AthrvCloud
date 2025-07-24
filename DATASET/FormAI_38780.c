//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include<stdio.h>
#include<string.h>

int main()
{
    char msg[100];
    printf("Welcome to our cheerful Spam Detection System! \n");
    printf("Please enter the message you want to check for spam: ");
    fgets(msg, 100, stdin);
    msg[strcspn(msg, "\n")] = 0; // Removing the '\n' character from the input string

    int len = strlen(msg);
    int count = 0;

    for(int i=0; i<len; i++)
    {
        // Checking for repeated characters
        if(msg[i] == msg[i+1])
        {
            count++;
        }

        // Checking for keywords associated with spam messages
        if((strstr(msg, "money") != NULL) || (strstr(msg, "win") != NULL) || (strstr(msg, "prize") != NULL) || (strstr(msg, "offer") != NULL))
        {
            count++;
        }
    }

    // Checking the number of spam related occurrences in the message
    if(count>=2)
    {
        printf("\nAlert! The message you entered is a spam message. Please be careful while opening messages from unknown sources.\n");
    }
    else
    {
        printf("\nGreat news! The message you entered is not a spam message. You can proceed with opening it.\n");
    }

    return 0;
}