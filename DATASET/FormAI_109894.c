//FormAI DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The size of the key used for encryption
#define KEY_SIZE 12

// Function to encrypt a message using the provided key
char* encrypt_message(char* message, char* key)
{
    char* encrypted_message = calloc(strlen(message), sizeof(char));

    for(int i = 0; i < strlen(message); i++)
    {
        // Get the corresponding key character for the current message character
        char key_char = key[i % KEY_SIZE];

        // XOR the message character and the key character together to encrypt it
        char encrypted_char = message[i] ^ key_char;

        // Add the encrypted character to the encrypted message string
        encrypted_message[i] = encrypted_char;
    }

    return encrypted_message;
}

int main()
{
    // The message to be encrypted
    char message[] = "This is a secret message!";

    // The encryption key
    char key[] = "mysecretkey1";

    // Encrypt the message using the key
    char* encrypted_message = encrypt_message(message, key);

    // Print the encrypted message to the console
    printf("Encrypted Message: %s\n", encrypted_message);

    // Free the allocated memory for the encrypted message
    free(encrypted_message);

    return 0;
}