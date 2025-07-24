//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void print_hex(unsigned char *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

void encrypt(unsigned char *key, unsigned char *iv, unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv, AES_ENCRYPT);
}

void decrypt(unsigned char *key, unsigned char *iv, unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aes_key, iv, AES_DECRYPT);
}

int main() {
    unsigned char key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    unsigned char iv[] = {0x8f, 0x87, 0xa6, 0x2d, 0xa9, 0xea, 0x46, 0xea, 0x36, 0x97, 0xf2, 0x61, 0x5a, 0xc6, 0x5d, 0xe0};
    unsigned char plaintext[] = "hello world";
    int plaintext_len = strlen((const char *) plaintext);
    unsigned char ciphertext[plaintext_len];
    unsigned char decrypted_plaintext[plaintext_len];

    printf("Plaintext: ");
    print_hex(plaintext, plaintext_len);

    encrypt(key, iv, plaintext, plaintext_len, ciphertext);
    printf("Ciphertext: ");
    print_hex(ciphertext, plaintext_len);

    decrypt(key, iv, ciphertext, plaintext_len, decrypted_plaintext);
    printf("Decrypted plaintext: ");
    print_hex(decrypted_plaintext, plaintext_len);

    return 0;
}