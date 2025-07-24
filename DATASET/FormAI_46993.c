//FormAI DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16

void encrypt(char *message, char *key, char *iv, char *output) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    unsigned char outputTemp[100];
    memset(outputTemp, 0, sizeof(outputTemp));
    AES_cbc_encrypt((unsigned char *) message, outputTemp, strlen(message), &aes_key, (unsigned char *) iv, AES_ENCRYPT);
    memcpy(output, outputTemp, AES_BLOCK_SIZE);
    memcpy(output + AES_BLOCK_SIZE, outputTemp + AES_BLOCK_SIZE, strlen(message));
}

void decrypt(char *message, char *key, char *iv, char *output) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    unsigned char outputTemp[100];
    memset(outputTemp, 0, sizeof(outputTemp));
    AES_cbc_encrypt((unsigned char *) message, outputTemp, strlen(message), &aes_key, (unsigned char *) iv, AES_DECRYPT);
    memcpy(output, outputTemp + AES_BLOCK_SIZE, strlen(message));
}

int main() {
    char message[] = "hello world!";
    char key[] = "thisIsTheEncryptionKey1234";
    char iv[] = "thisIsTheInitVector";
    char encryptedMessage[100];
    char decryptedMessage[100];
    encrypt(message, key, iv, encryptedMessage);
    printf("Encrypted message: %s\n", encryptedMessage);
    decrypt(encryptedMessage, key, iv, decryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);
    return 0;
}