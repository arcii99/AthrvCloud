//FormAI DATASET v1.0 Category: modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant size for the key and message.
#define KEY_SIZE 16
#define MSG_SIZE 128

// Define function to generate a random key.
void generate_key(char *key)
{
    int i;
    for(i = 0; i < KEY_SIZE; i++)
    {
        key[i] = rand() % 256; // Generate a random number between 0 and 255.
    }
}

// Define function to encrypt the message using the key.
void encrypt(char *key, char *msg)
{
    int i;
    int key_index = 0; // Index to keep track of the key array when encrypting.

    for(i = 0; i < strlen(msg); i++)
    {
        msg[i] ^= key[key_index]; // XOR the message with the key at the current index.

        if(++key_index == KEY_SIZE)
        {
            key_index = 0; // Reset the key index back to the first element.
        }
    }
}

// Define function to decrypt the message using the key.
void decrypt(char *key, char *msg)
{
    // Decrypting is just encrypting again with the same key.
    encrypt(key, msg);
}

int main()
{
    char key[KEY_SIZE];
    char message[MSG_SIZE] = "This is a secret message!";

    // Generate a random key.
    generate_key(key);

    // Print out the original message.
    printf("Original Message:\n%s\n", message);

    // Encrypt the message using the key.
    encrypt(key, message);

    // Print out the encrypted message.
    printf("Encrypted Message:\n%s\n", message);

    // Decrypt the message using the same key.
    decrypt(key, message);

    // Print out the decrypted message.
    printf("Decrypted Message:\n%s\n", message);

    return 0;
}