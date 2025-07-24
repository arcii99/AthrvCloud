//FormAI DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define KEY 5   // Define encryption key

void encrypt(char* message, int key)
{
    int i = 0;
    while (message[i] != '\0')
    {
        // Use bitwise XOR operation to encrypt message
        message[i] ^= key;

        // Increment i to move to next character
        i++;
    }
}

int main()
{
    char message[100];
    printf("Enter your message: ");
    scanf("%[^\n]%*c", message);   // Get user input

    encrypt(message, KEY);    // Encrypt the input message

    printf("\nEncrypted message: ");
    printf("%s\n", message);  // Print the encrypted message

    return 0;
}