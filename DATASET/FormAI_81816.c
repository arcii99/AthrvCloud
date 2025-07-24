//FormAI DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 20
#define MAX_INPUT_LENGTH 100

char *spamWords[MAX_SPAM_WORDS] = { "buy", "cheap", "sale", "viagra", "money", "refund", "offer", "limited time", "credit card", "win", "prize", "gift", "cash", "click here", "earn", "opportunity", "profits", "easy money", "discount", "investment" };

int main()
{
    char input[MAX_INPUT_LENGTH];
    int i, j;
    int spamCount = 0;
    
    printf("Enter a message to check for spam:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Convert the input to lowercase
    for(i = 0; i < MAX_INPUT_LENGTH; i++)
    {
        input[i] = tolower(input[i]);
    }
    
    // Check if any of the spam words are in the input
    for(i = 0; i < MAX_SPAM_WORDS; i++)
    {
        if(strstr(input, spamWords[i]) != NULL)
        {
            spamCount++;
        }
    }
    
    // If there are more than 2 spam words in the input, consider it spam
    if(spamCount > 2)
    {
        printf("\nSPAM DETECTED!\n");
    }
    else
    {
        printf("\nNOT SPAM\n");
    }
    
    return 0;
}