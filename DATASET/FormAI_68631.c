//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    AES_KEY aesKey;
    int status = AES_set_encrypt_key((const unsigned char *)"MySecretKey", 128, &aesKey); // Set the secret key for encryption
    if (status < 0) {
        fprintf(stderr, "Failed to set the encryption key\n");
        exit(1);
    }

    const unsigned char *plainText = (const unsigned char *)"Hello World!"; // The string to be encrypted
    int plainTextLength = strlen((const char *)plainText);

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE); // Initialization vector, can be any sequence of bytes

    unsigned char encryptedText[1024]; // The encrypted text
    memset(encryptedText, 0x00, 1024);

    AES_cbc_encrypt(plainText, encryptedText, plainTextLength, &aesKey, iv, AES_ENCRYPT); // Perform AES encryption

    printf("Encrypted Text: ");
    for (int i = 0; i < plainTextLength; i++) {
        printf("%02x", encryptedText[i]);
    }
    printf("\n");

    unsigned char decryptedText[1024]; // The decrypted text
    memset(decryptedText, 0x00, 1024);

    AES_set_decrypt_key((const unsigned char *)"MySecretKey", 128, &aesKey); // Set the secret key for decryption

    AES_cbc_encrypt(encryptedText, decryptedText, plainTextLength, &aesKey, iv, AES_DECRYPT); // Perform AES decryption
    decryptedText[plainTextLength] = '\0';

    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}