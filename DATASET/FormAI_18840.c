//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int key = 5; // Define a key for encryption shift
    
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin); // Input string from user
    
    int length = strlen(message); // Calculate length of message
    
    for(int i = 0; i < length; i++)
    {
        char ch = message[i];
        
        // Check if character is an uppercase letter
        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key; // Shift the character by key amount
            
            if(ch > 'Z') // If shifted character exceeds 'Z', wrap around
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch; // Update message with encrypted character
        }
        // Check if character is a lowercase letter
        else if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key; // Shift the character by key amount
            
            if(ch > 'z') // If shifted character exceeds 'z', wrap around
            {
                ch = ch - 'z' + 'a' - 1;
            }
            
            message[i] = ch; // Update message with encrypted character
        }
        // Character is not a letter, do not encrypt
        else
        {
            continue;
        }
    }
    
    printf("Encrypted message: %s", message); // Output encrypted message
    
    return 0;
}