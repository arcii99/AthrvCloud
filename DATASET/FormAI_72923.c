//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <string.h>

// Function to check if a given string is spam or not
int is_spam(char message[])
{
    int i, j, count;
    
    // List of blacklisted words
    char blacklist[][10] = {"buy", "sale", "offer", "cheap", "discount"};
    
    // Split the message into individual words
    char *token = strtok(message, " ");
    
    while(token != NULL)
    {
        count = 0;
        for (i = 0; i < strlen(token); i++)
        {
            // Convert every letter to lowercase for comparison
            token[i] = tolower(token[i]);
        }
        
        // Check if the word is blacklisted
        for (j = 0; j < 5; j++)
        {
            if (strcmp(token, blacklist[j]) == 0)
            {
                count++;
            }
        }
        
        // If the word is blacklisted more than once, return 1 (spam)
        if (count > 1)
        {
            return 1;
        }
        
        token = strtok(NULL, " ");
    }
    
    // If no blacklisted words are found, return 0 (not spam)
    return 0;
}

int main()
{
    char message[100];
    
    // Get user input for message
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    
    // Check if the message is spam or not
    if (is_spam(message))
    {
        printf("This message is spam!\n");
    }
    else
    {
        printf("This message is not spam.\n");
    }
    
    return 0;
}