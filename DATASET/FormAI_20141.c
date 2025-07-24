//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_KEYLEN 256

int main()
{
    unsigned char key[AES_KEYLEN/8];
    char plaintext[100] = "This is a secret message!";
    unsigned char ciphertext[100];
    unsigned char decrypttext[100];

    // Generate a random key
    FILE* dev_random = fopen("/dev/urandom", "r");
    if(dev_random == NULL) {
        printf("Error opening /dev/urandom\n");
        exit(1);
    }
    fread(key, AES_KEYLEN/8, 1, dev_random);
    fclose(dev_random);

    // Create AES key
    AES_KEY aes_key;
    AES_set_encrypt_key(key, AES_KEYLEN, &aes_key);

    // Encrypt plaintext
    int plaintext_len = strlen(plaintext) + 1;
    int num_blocks = plaintext_len / AES_BLOCK_SIZE + 1;
    int ciphertext_len = AES_BLOCK_SIZE * num_blocks;
    memset(ciphertext, 0, ciphertext_len);
    AES_encrypt(plaintext, ciphertext, &aes_key);

    // Decrypt ciphertext
    AES_KEY aes_decrypt_key;
    AES_set_decrypt_key(key, AES_KEYLEN, &aes_decrypt_key);
    AES_decrypt(ciphertext, decrypttext, &aes_decrypt_key);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypttext: %s\n", decrypttext);

    return 0;
}