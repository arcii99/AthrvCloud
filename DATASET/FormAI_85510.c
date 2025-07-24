//FormAI DATASET v1.0 Category: Spam Detection System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[256];
    printf("Enter a message: ");
    fgets(message, 256, stdin);
    int i, j, k, spam = 0;

    // Check for excessive use of exclamation marks
    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] == '!')
        {
            spam++;
        }
        else if(message[i] != ' ' && message[i] != '\n')
        {
            spam = 0;
        }
        if(spam > 3)
        {
            printf("SPAM DETECTED: Excessive use of exclamation marks.\n");
            return 0;
        }
    }

    // Check for repeated words
    char *word = strtok(message, " ,.-\n");
    while(word != NULL)
    {
        k = strlen(word);
        for(i = 0; i < k - 2; i++)
        {
            for(j = i + 1; j < k - 1; j++)
            {
                if(word[i] == word[j] && word[i+1] == word[j+1] && word[i+2] == word[j+2])
                {
                    printf("SPAM DETECTED: Repeated word '%s'.\n", word);
                    return 0;
                }
            }
        }
        word = strtok(NULL, " ,.-\n");
    }

    printf("Message passed spam detection test.\n");
    return 0;
}