//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Function to encrypt a message using Caesar cipher
void caesarCipherEncrypt(char message[], int key)
{
    // Traverse through each character of the message
    for(int i = 0; i < strlen(message); i++)
    {
        // If the current character is uppercase alphabet
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            // Add key to the character's ASCII code
            message[i] = (char) (((int) message[i] - 65 + key) % 26 + 65);
        }
        // If the current character is lowercase alphabet
        else if(message[i] >= 'a' && message[i] <= 'z')
        {
            // Add key to the character's ASCII code
            message[i] = (char) (((int) message[i] - 97 + key) % 26 + 97);
        }
    }
}

int main()
{
    // Declare and initialize the message and key
    char message[] = "Hello World!";
    int key = 3;

    // Display the original message
    printf("Original Message: %s\n", message);

    // Encrypt the message using Caesar Cipher
    caesarCipherEncrypt(message, key);

    // Display the encrypted message
    printf("Encrypted Message: %s\n", message);

    return 0;
}