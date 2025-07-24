//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 1000
#define MAX_SPAM_MSGS 50

int main()
{
    char msg[MAX_MSG_SIZE];
    char spam_msgs[MAX_SPAM_MSGS][MAX_MSG_SIZE] = {
        "Make money fast",
        "Multi-level marketing",
        "Get rich quick",
        "Enlarge your penis",
        "Viagra for sale",
        "Nigerian prince",
        "Free gift",
        "You've won a prize",
        "Limited time offer",
        "Exclusive deal",
        "Act now",
        "Call now",
        "Buy now",
        "Order now",
        "Special offer"
    };

    printf("Enter a message: ");
    fgets(msg, MAX_MSG_SIZE, stdin);
    msg[strcspn(msg, "\n")] = 0; // remove newline character

    int i;
    for(i = 0; i < MAX_SPAM_MSGS; i++)
    {
        if(strstr(msg, spam_msgs[i]) != NULL)
        {
            printf("SPAM DETECTED!\n");
            exit(EXIT_SUCCESS);
        }
    }

    printf("Message is not spam.\n");

    return 0;
}