//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext) {
    AES_KEY enc_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext) {
    AES_KEY dec_key;
    AES_set_decrypt_key(key, 128, &dec_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &dec_key, iv, AES_DECRYPT);
}

int main() {
    unsigned char *key = (unsigned char *)"abcdefghijklmnopqrstuvwxyz012345";
    unsigned char *iv = (unsigned char *)"1234567890123456";
    unsigned char plaintext[] = "Hello, World!";
    int plaintext_len = strlen((char *)plaintext);

    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    decrypt(ciphertext, plaintext_len, key, iv, decryptedtext);

    printf("Plain text: %s\n", plaintext);
    printf("Cipher text: ");
    for(int i=0; i<plaintext_len; i++){
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}