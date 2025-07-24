//FormAI DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000];
    int spam = 0;
    
    printf("Enter the message: ");
    fgets(message, 1000, stdin); // To get input from user

    char spamWords[5][12] = {"win", "cash", "free", "prize", "buy"}; // List of spam words
    
    for(int i = 0; i < strlen(message); i++) 
    {
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = message[i] + 32; // Converting to lowercase
        }
    }
    
    for(int i = 0; i < 5; i++) // Check for spam words
    {
        if(strstr(message, spamWords[i])) // Checking if spam word is present
        {
            spam = 1; // If present, spam variable is set to true
            break;
        }
    }
    
    if(spam == 1)
    {
        printf("This message is spam!\n"); 
    }
    else
    {
        printf("This message is not spam!\n");
    }
    
    return 0;
}