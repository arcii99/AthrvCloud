//FormAI DATASET v1.0 Category: Spam Detection System ; Style: lively
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000];
    int count = 0;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin); // get user input

    char *spam_words[] = {"buy now", "limited time offer", "make money fast", "never pay again"};

    for(int i = 0; i < strlen(message); i++)
    {
        if(message[i] == ' ') // check if space
        {
            count++; // increment word count
        }

        for(int j = 0; j < 4; j++) // check for spam words
        {
            if(strstr(message, spam_words[j]) != NULL) // spam word found
            {
                printf("Warning: Possible spam detected.\n");
                return 0;
            }
        }
    }

    if(count >= 10) // check word count
    {
        printf("Warning: Possible spam detected.\n");
    }
    else
    {
        printf("Message received.\n");
    }

    return 0;
}