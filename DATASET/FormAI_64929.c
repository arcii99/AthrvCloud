//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

/* Functions declarations */
void generate_key(char* key);
void generate_nonce(char* nonce);
void encrypt(char *plaintext, char *key, char *nonce, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *nonce, char *plaintext);
void print_hex(unsigned char *data, int len);
void print_usage();

/* Main function */
int main(int argc, char **argv)
{
    if (argc != 2) {
        print_usage();
        return 1;
    }

    char key[KEY_SIZE];
    generate_key(key);

    char nonce[BLOCK_SIZE];
    generate_nonce(nonce);

    char *plaintext = argv[1];
    int plaintext_len = strlen(plaintext);

    char ciphertext[plaintext_len + BLOCK_SIZE];
    encrypt(plaintext, key, nonce, ciphertext);

    printf("\nGenerated key: ");
    print_hex((unsigned char *)key, sizeof(key));
    printf("\nGenerated nonce: ");
    print_hex((unsigned char *)nonce, sizeof(nonce));
    printf("\nPlaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    print_hex((unsigned char *)ciphertext, sizeof(ciphertext));

    char decrypted_plaintext[plaintext_len];
    decrypt(ciphertext, key, nonce, decrypted_plaintext);
    decrypted_plaintext[plaintext_len] = 0;

    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}

/* Generate a random key */
void generate_key(char* key)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
}

/* Generate a random nonce */
void generate_nonce(char* nonce)
{
    srand(time(NULL));
    for (int i = 0; i < BLOCK_SIZE; i++) {
        nonce[i] = rand() % 256;
    }
}

/* Encrypt a plaintext using AES-128 in CTR mode */
void encrypt(char *plaintext, char *key, char *nonce, char *ciphertext)
{
    int plaintext_len = strlen(plaintext);

    int blocks = plaintext_len / BLOCK_SIZE + (plaintext_len % BLOCK_SIZE != 0);
    char key_stream[BLOCK_SIZE * blocks];
    char encrypted_block[BLOCK_SIZE];

    for (int i = 0; i < blocks; i++) {
        /* Generate keystream block */
        char counter[BLOCK_SIZE];
        memcpy(counter, nonce, BLOCK_SIZE);
        counter[BLOCK_SIZE - 1] += i;
        // TODO: Implement AES-128

        /* XOR plaintext with keystream block */
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (i * BLOCK_SIZE + j < plaintext_len) {
                ciphertext[i * BLOCK_SIZE + j] = plaintext[i * BLOCK_SIZE + j] ^ key_stream[i * BLOCK_SIZE + j];
            } else {
                ciphertext[i * BLOCK_SIZE + j] = 0;
            }
        }
    }
}

/* Decrypt a ciphertext using AES-128 in CTR mode */
void decrypt(char *ciphertext, char *key, char *nonce, char *plaintext)
{
    int ciphertext_len = BLOCK_SIZE * ((strlen(ciphertext) - 1) / BLOCK_SIZE + 1);
    int blocks = ciphertext_len / BLOCK_SIZE;

    char key_stream[BLOCK_SIZE * blocks];
    char decrypted_block[BLOCK_SIZE];

    for (int i = 0; i < blocks; i++) {
        /* Generate keystream block */
        char counter[BLOCK_SIZE];
        memcpy(counter, nonce, BLOCK_SIZE);
        counter[BLOCK_SIZE - 1] += i;
        // TODO: Implement AES-128

        /* XOR ciphertext with keystream block */
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (i * BLOCK_SIZE + j < ciphertext_len) {
                plaintext[i * BLOCK_SIZE + j] = ciphertext[i * BLOCK_SIZE + j] ^ key_stream[i * BLOCK_SIZE + j];
            } else {
                plaintext[i * BLOCK_SIZE + j] = 0;
            }
        }
    }
}

/* Print data in hexadecimal format */
void print_hex(unsigned char *data, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%02X", data[i]);
    }
}

/* Print usage information */
void print_usage()
{
    printf("Usage: crypt [plaintext]\n");
}