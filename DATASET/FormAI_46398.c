//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000];
    int spam_count = 0, non_spam_count = 0;

    printf("Enter the messages(enter exit to stop): \n");

    while (1)
    {
        // read input message
        fgets(message, 1000, stdin);

        // check if user wants to exit
        if(strcmp("exit\n", message) == 0)
            break;

        // check if message contains spam keywords
        if(strstr(message, "win") || strstr(message, "cash") || strstr(message, "prize") || strstr(message, "offer"))
            spam_count++;
        else
            non_spam_count++;
    }

    printf("\nNumber of spam messages: %d\n", spam_count);
    printf("Number of non-spam messages: %d\n", non_spam_count);

    // classify the user as spammer/non-spammer based on spam count
    if(spam_count > 0 && spam_count > non_spam_count)
        printf("\nYou are a spammer!\n");
    else
        printf("\nYou are not a spammer!\n");

    return 0;
}