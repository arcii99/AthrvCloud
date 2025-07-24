//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000];
    printf("Enter a message: ");
    fgets(message, 1000, stdin);

    int length = strlen(message);
    int num_spam_words = 0;
    char *spam_words[10] = {"buy", "sale", "cheap", "discount", "credit card", "online pharmacy", "earn money", "work from home", "make money", "investment"};

    // Check if any spam words are present in the message
    for (int i = 0; i < 10; i++)
    {
        if (strstr(message, spam_words[i]))
        {
            num_spam_words++;
        }
    }

    // If more than 2 spam words are present, mark message as spam
    if (num_spam_words > 2)
    {
        printf("This message is spam.");
    }
    else
    {
        printf("This message is not spam.");
    }

    return 0;
}