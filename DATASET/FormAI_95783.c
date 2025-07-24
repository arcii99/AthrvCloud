//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Romeo and Juliet
// Romeo and Juliet Spam Detection System

#include <stdio.h>
#include <string.h>

int main()
{
    char spamWords[5][20] = {"buy", "free", "discount", "spam", "limited"};
    char message[200];

    printf("Oh Romeo! Our inbox is full of messages. Let's check for some spam.\n");
    printf("Enter your message here:\n");
    fgets(message, 200, stdin);

    int spamFlag = 0;

    for(int i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'A' && message[i] <= 'Z')
            message[i] += 32; // converting uppercase to lowercase

        if(message[i] == ' ' || message[i] == '\n' || message[i] == '\t' || message[i] == '\0')
        {
            char word[20];
            int wordLength = i - spamFlag;

            if(wordLength > 0) // for avoiding empty space
            {
                for(int j = 0; j < wordLength; j++)
                {
                    word[j] = message[spamFlag + j];
                }
                word[wordLength] = '\0';

                for(int k = 0; k < 5; k++)
                {
                    if(strcmp(word, spamWords[k]) == 0)
                    {
                        printf("Oh no! This message contains spam.\n");
                        return 0;
                    }
                }
            }
            spamFlag = i + 1; // resetting the spam flag after each space
        }
    }

    printf("Phew! We couldn't find any spam in this message.\n");

    return 0;

}