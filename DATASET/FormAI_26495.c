//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10

char *spamWords[MAX_SPAM_WORDS] = {"Viagra", "Nigeria", "Free money", "Lottery", "Enlarge", "Dollars", "Limited time offer", "Urgent", "Congratulations", "Meet singles"};

int main()
{
    char message[1000];
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

    int count = 0;
    char *token = strtok(message, " ");
    while (token != NULL)
    {
        for (int i = 0; i < MAX_SPAM_WORDS; i++)
        {
            if (strcasecmp(token, spamWords[i]) == 0)
            {
                count++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (count >= 2)
    {
        printf("SPAM DETECTED! The message has %d spam words.\n", count);
    }
    else
    {
        printf("Message is not spam.\n");
    }

    return 0;
}