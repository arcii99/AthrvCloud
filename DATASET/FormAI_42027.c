//FormAI DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MSG_LEN 1000
#define MAX_SPAM_WORDS 8

char SPAM_WORDS[MAX_SPAM_WORDS][20] = {"make money", "earn money", "get rich", "contacts", "investment opportunity", "limited time offer", "free gift", "one time offer"};

// function to check if a word is a spam word
int is_spam(char *word)
{
    for(int i=0; i<MAX_SPAM_WORDS; i++)
    {
        if(strcmp(word, SPAM_WORDS[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// function to check if a message contains spam words
int has_spam(char *message)
{
    char *token = strtok(message, " "); // tokenize message by space
    while(token != NULL)
    {
        if(is_spam(token))
        {
            return 1;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int main()
{
    char message[MAX_MSG_LEN];
    printf("Enter message: ");
    fgets(message, MAX_MSG_LEN, stdin);

    if(has_spam(message))
    {
        printf("Message detected as spam.\n");
    }
    else
    {
        printf("Message is not spam.\n");
    }

    return 0;
}