//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include<stdio.h>
#include<ctype.h>
#include<string.h>

// Function to check for spam words
int findSpamWord(char message[])
{
    int count = 0;
    char spamWords[5][20] = {"buy", "sale", "money", "offer", "promote"};
    char *word = strtok(message, " ,.-");

    while(word != NULL)
    {
        for(int i=0; i<5; i++)
        {
            if(strcmp(word, spamWords[i]) == 0)
            {
                count++;
            }
        }
        word = strtok(NULL, " ,.-");
    }

    return count;
}

// Main function to check for spam messages
int main()
{
    char message[500];
    printf("Enter a message: ");
    gets(message);

    int count = findSpamWord(message);

    if(count >= 2)
    {
        printf("This message contains spam words and is SPAM!");
    }
    else
    {
        printf("This message is not spam.");
    }

    return 0;
}