//FormAI DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>

// Function to detect spam in messages
int spamDetector(char *msg)
{
    int count = 0;
    char spamWords[5][20] = {"offer", "discount", "sale", "buy", "free"};

    // Loop through the words in the message
    char *word = strtok(msg, " ");
    while (word != NULL)
    {
        // Check if the word matches any of the spam words
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(word, spamWords[i]) == 0)
            {
                count++;
            }
        }
        word = strtok(NULL, " ");
    }

    // Check if the message contains more than two spam words
    if (count >= 2)
    {
        return 1;
    }

    return 0;
}

int main()
{
    char message[100];

    printf("My love, please enter your message to me: ");
    fgets(message, sizeof(message), stdin);

    // Check if message is spam
    if (spamDetector(message))
    {
        printf("My love, your message seems like spam. Please try again.\n");
    }
    else
    {
        printf("My love, your message is beautiful, just like you.\n");
    }

    return 0;
}