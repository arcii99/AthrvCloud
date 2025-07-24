//FormAI DATASET v1.0 Category: modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The key used for encryption purposes.*/
const char key = 'K';

/* Function to encrypt the given message. */
void encrypt(char *message, int len)
{
    for (int i = 0; i < len; i++)
    {
        message[i] = message[i] ^ key;   /* XOR operation between the key and character in the message.*/
    }
}

/* Function to decrypt the given message. */
void decrypt(char *message, int len)
{
    encrypt(message, len);   /* Decryption is same as encryption, so calling the same function.*/
}

int main()
{
    char message[100], decipher[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin); /* Taking the user message from command prompt.*/

    int len = strlen(message) - 1;  /* Removing the newline character from user input.*/

    encrypt(message, len);  /* Encrypting the message with the given key.*/

    printf("Encrypted message: %s\n", message);

    decrypt(message, len);  /* Decrypting the message by using the same key.*/

    printf("Decrypted message: %s\n", message);

    return 0;
}