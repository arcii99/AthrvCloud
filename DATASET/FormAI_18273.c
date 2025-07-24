//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32

unsigned char key[KEY_SIZE];
unsigned char iv[BLOCK_SIZE];

void generate_key()
{
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++)
    {
        key[i] = rand() % 256;
    }
}

void generate_iv()
{
    srand(time(NULL));
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        iv[i] = rand() % 256;
    }
}

void encrypt(char *plaintext, unsigned char *ciphertext, int len)
{
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 256, &aes_key);
    int blocks = len / BLOCK_SIZE + 1;
    unsigned char block[BLOCK_SIZE];
    for (int i = 0; i < blocks; i++)
    {
        memset(block, 0, BLOCK_SIZE);
        int start = i * BLOCK_SIZE;
        int end = start + BLOCK_SIZE;
        if (end > len)
        {
            end = len;
        }
        int block_len = end - start;
        memcpy(block, plaintext + start, block_len);
        AES_cbc_encrypt(block, ciphertext + start, block_len, &aes_key, iv, AES_ENCRYPT);
    }
}

void decrypt(unsigned char *ciphertext, char *plaintext, int len)
{
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 256, &aes_key);
    int blocks = len / BLOCK_SIZE + 1;
    unsigned char block[BLOCK_SIZE];
    for (int i = 0; i < blocks; i++)
    {
        memset(block, 0, BLOCK_SIZE);
        int start = i * BLOCK_SIZE;
        int end = start + BLOCK_SIZE;
        if (end > len)
        {
            end = len;
        }
        int block_len = end - start;
        memcpy(block, ciphertext + start, block_len);
        AES_cbc_encrypt(block, plaintext + start, block_len, &aes_key, iv, AES_DECRYPT);
    }
}

int main()
{
    char plaintext[1000] = "Hello, World!";
    unsigned char ciphertext[1000];
    generate_key();
    generate_iv();
    int len = strlen(plaintext);
    encrypt(plaintext, ciphertext, len);
    for (int i = 0; i < len; i++)
    {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");
    char decrypted[1000];
    decrypt(ciphertext, decrypted, len);
    printf("%s\n", decrypted);
    return 0;
}