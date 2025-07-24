//FormAI DATASET v1.0 Category: Spam Detection System ; Style: lively
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_WORD_LENGTH 20

char spam_words[MAX_SPAM_WORDS][MAX_WORD_LENGTH] = {"free", "discount", "offer", "win", "lottery", "cash", "money", "urgent", "guaranteed", "act now"};

int main()
{
    char message[1000];
    int spam_count = 0;

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin); // get input from user
    printf("\n");

    // check for spam words in the message
    for(int i=0; i<strlen(message); i++)
    {
        if(message[i] == ' ' || message[i] == '\n')
        {
            continue;
        }

        int j = 0;
        char word[MAX_WORD_LENGTH];

        while(message[i] != ' ' && message[i] != '\n' && j < MAX_WORD_LENGTH-1)
        {
            word[j++] = tolower(message[i++]);
        }

        word[j] = '\0';

        for(int k=0; k<MAX_SPAM_WORDS; k++)
        {
            if(strcmp(word, spam_words[k]) == 0)
            {
                spam_count++;
                break;
            }
        }
    }

    // decide if the message is spam or not
    if(spam_count >= 2)
    {
        printf("Warning: This message may be spam!\n");
    }
    else
    {
        printf("Success: This is not a spam message.\n");
    }

    return 0;
}