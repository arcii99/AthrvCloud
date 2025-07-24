//FormAI DATASET v1.0 Category: Spam Detection System ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10

char *spam_words[MAX_SPAM_WORDS] = {"free", "offer", "money", "limited", "special", "deal", "click", "win", "buy", "discount"};

int main()
{
    char message[1000];
    int spam_count = 0;

    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    // convert all characters to lowercase
    for (int i = 0; message[i]; i++)
    {
        message[i] = tolower(message[i]);
    }

    // check for spam words
    for (int i = 0; i < MAX_SPAM_WORDS; i++)
    {
        if (strstr(message, spam_words[i]) != NULL)
        {
            spam_count++;
        }
    }

    // classify the message as spam or not
    if (spam_count > 0)
    {
        printf("The message is classified as SPAM with %d occurrences of spam words.", spam_count);
    }
    else
    {
        printf("The message is classified as NOT SPAM.");
    }

    return 0;
}