//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main()
{
    printf("My love, I want to encrypt my heart with the most secure encryption algorithm in the world. That's why I chose the Advanced Encryption Standard (AES).\n\n");

    unsigned char key[AES_BLOCK_SIZE];
    memset(key, 0x00, AES_BLOCK_SIZE);
    strcpy(key, "myloveisasecret");

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, AES_BLOCK_SIZE * 8, &aes_key) < 0)
    {
        printf("Failed to set encrypt key!\n");
        exit(-1);
    }

    char message[100];
    printf("Please enter your message: ");
    gets(message);

    unsigned char encrypted_message[AES_BLOCK_SIZE];
    memset(encrypted_message, 0x00, AES_BLOCK_SIZE);

    AES_cbc_encrypt(message, encrypted_message, strlen(message), &aes_key, iv, AES_ENCRYPT);

    printf("\nYour encrypted message: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++)
    {
        printf("%02X", encrypted_message[i]);
    }

    printf("\n\n");
    return 0;
}