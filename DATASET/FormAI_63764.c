//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 5

int main()
{
    char input[100]; // Input string
    char output[100]; // Encrypted string
    int len = 0; // Length of input string
   
    printf("Enter a message to be encrypted: ");
    fgets(input, 100, stdin); // Read input string from user
    
    len = strlen(input); // Get length of input string
    
    // Loop through each character of input string and encrypt
    for(int i=0; i<len; i++)
    {
        // If the character is a lowercase letter, encrypt it
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            output[i] = (((input[i] + KEY) - 'a') % 26) + 'a';
        }
        // If the character is an uppercase letter, encrypt it
        else if(input[i] >= 'A' && input[i] <= 'Z')
        {
            output[i] = (((input[i] + KEY) - 'A') % 26) + 'A';
        }
        // Otherwise, leave it unchanged
        else
        {
            output[i] = input[i];
        }
    }
    
    printf("Encrypted message: %s\n", output); // Print the encrypted string
    
    return 0;
}