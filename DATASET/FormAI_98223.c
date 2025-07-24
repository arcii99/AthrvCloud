//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

int main()
{
    // Seed the random generator with current time
    srand(time(0));

    // Generate a random key
    unsigned char key[KEY_SIZE];
    for(int i = 0; i < KEY_SIZE; i++)
    {
        key[i] = rand() % 256; // Generate values between 0-255
    }

    // Get the message from the user
    printf("Enter a message to encrypt:");
    char message[1000];
    fgets(message, 1000, stdin);

    // Calculate the length of the message
    int message_length = strlen(message);

    // Pad the message to be a multiple of the block size
    int padded_length = (message_length / BLOCK_SIZE + 1) * BLOCK_SIZE;
    char padded_message[padded_length];
    strcpy(padded_message, message);
    for(int i = message_length; i < padded_length; i++)
    {
        padded_message[i] = rand() % 256; // Use random values to pad the message
    }

    // Encrypt the message using the key
    int blocks = padded_length / BLOCK_SIZE;
    unsigned char encrypted_message[padded_length];
    for(int i = 0; i < blocks; i++)
    {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, padded_message + i * BLOCK_SIZE, BLOCK_SIZE);
        for(int j = 0; j < BLOCK_SIZE; j++)
        {
            block[j] = block[j] ^ key[j]; // XOR each byte with the corresponding byte in the key
        }
        memcpy(encrypted_message + i * BLOCK_SIZE, block, BLOCK_SIZE);
    }

    // Print the encrypted message
    printf("Encrypted message:");
    for(int i = 0; i < padded_length; i++)
    {
        printf("%02x", encrypted_message[i]); // Print the byte value as a hexadecimal number
    }

    // Decrypt the message using the key
    unsigned char decrypted_message[padded_length];
    for(int i = 0; i < blocks; i++)
    {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, encrypted_message + i * BLOCK_SIZE, BLOCK_SIZE);
        for(int j = 0; j < BLOCK_SIZE; j++)
        {
            block[j] = block[j] ^ key[j]; // XOR each byte with the corresponding byte in the key
        }
        memcpy(decrypted_message + i * BLOCK_SIZE, block, BLOCK_SIZE);
    }

    // Print the decrypted message
    printf("\nDecrypted message:%s", decrypted_message);

    return 0;
}