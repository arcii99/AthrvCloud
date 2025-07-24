//FormAI DATASET v1.0 Category: Spam Detection System ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 100
#define MAX_SPAM_WORDS 5

char spam_words[MAX_SPAM_WORDS][MAX_MSG_LENGTH] = {"free", "money", "win", "lottery", "prize"};
//array of spam words to check against

int check_spam_words(char *message)
{
    char *token = strtok(message, " ,.!-"); //split message into tokens
    int count = 0;
    while(token != NULL)
    {
        for(int i=0; i<MAX_SPAM_WORDS; i++)
        {
            if(strcmp(token, spam_words[i]) == 0)
            {
                count++; //increment if spam word found
            }
        }
        token = strtok(NULL, " ,.!-"); //get next token
    }

    return count;
}

int main()
{
    char message[MAX_MSG_LENGTH];
    printf("Enter your message: ");
    fgets(message, MAX_MSG_LENGTH, stdin); //get message from user

    int spam_count = check_spam_words(message);

    if(spam_count > 0)
    {
        printf("SPAM DETECTED! The message contains %d spam word(s).\n", spam_count);
    }
    else
    {
        printf("No spam detected.\n");
    }

    return 0;
}