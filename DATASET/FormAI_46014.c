//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *p, int n); // Function prototype

int main()
{
    char message[100];      // Declare char array to store message

    printf("Enter your message: ");
    fgets(message, 100, stdin); // Take input message from user

    int len = strlen(message);  // Find length of message
    if (message[len-1] == '\n') 
        message[len-1] = '\0';  // Remove newline character from the message

    printf("\nOriginal Message: %s\n", message); // Print original message

    encrypt(message, len); // Call encrypt function to encrypt the message

    printf("Encrypted Message: %s\n", message); // Print encrypted message

    return 0;
}

// Function to encrypt the message
void encrypt(char *p, int n)
{
    // Loop through each character in the message and add 1 to its ASCII value
    for(int i=0; i<n; i++)
    {
        if(p[i] != ' ')
        {
            p[i] = (char)(p[i]+1);
        }
    }
}