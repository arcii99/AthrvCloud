//FormAI DATASET v1.0 Category: Spam Detection System ; Style: real-life
#include <stdio.h>
#include <string.h>

int main()
{
    // Initializing the spam words
    char spamWords[5][20] = {"make money fast", "earn cash now", "100% free", "cheap viagra", "meet singles"};
    // Initializing the user input
    char userInput[500];
    
    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter your message:\n");
    fgets(userInput, 500, stdin);

    int len = strlen(userInput);
    // Replacing newline with null character
    if (len > 0 && userInput[len-1] == '\n')
    {
        userInput[len-1] = '\0';
    }

    // Checking if the message contains any spam words
    int i, j, found;
    for(i=0; i<5; i++)
    {
        found = 0;
        j = 0;
        
        while(userInput[j] != '\0')
        {
            if(userInput[j] == spamWords[i][0])
            {
                int k = 1;
                while(spamWords[i][k] != '\0')
                {
                    if(spamWords[i][k] != userInput[j+k])
                    {
                        break;
                    }
                    k++;
                }
                
                if(spamWords[i][k] == '\0')
                {
                    found = 1;
                }
            }
            j++;
        }
        
        if(found)
        {
            printf("This message contains spam. Please try again.\n");
            break;
        }
    }

    // If message does not contain spam words
    if(!found)
    {
        printf("This message does not contain any spam. Thank you!\n");
    }
    
    return 0;
}