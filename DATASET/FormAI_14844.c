//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using a key
void encrypt(char *message, char *key)
{
    int length = strlen(message);
    int key_length = strlen(key);

    // Generating a repeating key for the length of the message
    char *new_key = (char *) malloc(sizeof(char) * length);
    for (int i = 0, j = 0; i < length; i++, j++)
    {
        if (j == key_length)
            j = 0;
        new_key[i] = key[j];
    }

    // Applying XOR operation to the message and the key
    for (int i = 0; i < length; i++)
        message[i] = message[i] ^ new_key[i];

    free(new_key);
}

int main()
{
    char message[100], key[100];

    // Getting the message and the key from the user
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    fgets(key, 100, stdin);

    // Removing the newline character from the message and the key
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Encrypting the message using the key
    encrypt(message, key);

    // Displaying the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}