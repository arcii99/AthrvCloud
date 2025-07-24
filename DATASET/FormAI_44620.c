//FormAI DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100];
    int i, spam = 0;     //initializing spam to 0

    printf("Enter your message here: ");
    gets(message);

    char *spam_words[] = {"offer", "free", "prize", "claim", "win"};   //list of spam words

    for(i=0; i<5; i++)    //checking if spam words are present in the message
    {
        if(strstr(message, spam_words[i]) != NULL)
        {
            spam = 1;
            break;     //if spam word found, break out of the loop
        }
    }

    if(spam)    //if spam = 1, message is considered as spam
    {
        printf("\n\nWARNING: This message is identified as SPAM!\n\n");
    }
    else    //if spam = 0, message is not spam
    {
        printf("\n\nThis message is NOT identified as SPAM.\n\n");
    }

    return 0;
}