//FormAI DATASET v1.0 Category: Spam Detection System ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Function to detect spam messages
int detectSpam(char message[])
{
    int spam = 0;
    
    // List of spam keywords
    char spamKeywords[5][20] = {"free", "offer", "click", "discount", "limited time"};
    
    // Loop through each keyword to check if it exists in the message
    for(int i=0; i<5; i++)
    {
        if(strstr(message, spamKeywords[i]) != NULL)
        {
            spam = 1; // If keyword is found, set spam flag to 1
            break; // Exit loop if spam is detected
        }
    }
    
    return spam;
}

int main()
{
    char message[1000];
    
    printf("Enter your message: ");
    fgets(message, 1000, stdin); // Read input message from user
    
    int isSpam = detectSpam(message);
    
    if(isSpam == 1)
    {
        printf("WARNING: Your message contains spam keywords.\n");
    }
    else
    {
        printf("Your message is safe to send.\n");
    }
    
    return 0;
}