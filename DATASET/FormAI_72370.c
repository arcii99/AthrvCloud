//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

/* Encrypts the given plaintext with the given key using AES-256 CBC */
void aes_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 256, &aes_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv, AES_ENCRYPT);
}

/* Decrypts the given ciphertext with the given key using AES-256 CBC */
void aes_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 256, &aes_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aes_key, iv, AES_DECRYPT);
}

/* Generates a random 256-bit key */
void generate_key(unsigned char *key)
{
    RAND_bytes(key, 32);
}

/* Generates a random 128-bit IV */
void generate_iv(unsigned char *iv)
{
    RAND_bytes(iv, 16);
}

int main()
{
    int plaintext_len, ciphertext_len;
    unsigned char *plaintext = (unsigned char *)"Hello, world!";
    unsigned char key[32], iv[16], ciphertext[16], decrypted_plaintext[16];

    generate_key(key);
    generate_iv(iv);

    plaintext_len = strlen((char *)plaintext);
    ciphertext_len = (plaintext_len / 16 + 1) * 16;

    aes_encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    aes_decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < sizeof(key); i++)
    {
        printf("%02x", key[i]);
    }
    printf("\nIV: ");
    for (int i = 0; i < sizeof(iv); i++)
    {
        printf("%02x", iv[i]);
    }
    printf("\nCiphertext: ");
    for (int i = 0; i < sizeof(ciphertext); i++)
    {
        printf("%02x", ciphertext[i]);
    }
    printf("\nDecrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}