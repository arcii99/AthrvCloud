//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>

/* Function to detect spam messages */
int detect_spam(char message[])
{
    // List of spam keywords to look for
    char spam_words[5][20] = {"win", "prize", "free", "offer", "promotion"};
    
    // Tokenize the message using space as the delimiter
    char *token = strtok(message, " ");
    
    while (token != NULL)
    {
        // Convert token to lowercase for case-insensitive comparison
        char lower_token[20];
        for (int i=0; i<strlen(token); i++)
            lower_token[i] = tolower(token[i]);
        lower_token[strlen(token)] = '\0';
        
        // Check if the token matches any of the spam keywords
        for (int i=0; i<5; i++)
        {
            if (strstr(lower_token, spam_words[i]) != NULL)
                return 1; // Spam detected!
        }
        
        // Get the next token
        token = strtok(NULL, " ");
    }
    
    return 0; // No spam detected
}

int main()
{
    char message[100];
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    
    if (detect_spam(message))
        printf("Oops! This looks like spam.\n");
    else
        printf("Your message seems to be okay.\n");
        
    return 0;
}