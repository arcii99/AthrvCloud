//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/evp.h>

/*
* This is a happy implementation of the C Cryptography library using OpenSSL.
* We create a function `encrypt` that accepts a plain-text message and a key,
* and returns the encrypted message. We then create a function `decrypt` that
* accepts an encrypted message and a key, and returns the decrypted plain-text.
* 
* Just for fun, we use a random salt for key derivation and print a happy message
* every time the functions are called. Cryptography is fun!
*/

#define CHUNK_SIZE 1024

char *encrypt(char *message, char *key) {
    printf("Encryption time! Let's make that message super secure!\n");
    srand(time(NULL));
    unsigned char salt[8];
    for (int i = 0; i < 8; i++) {
        salt[i] = rand() % 256;
    }
    unsigned char iv[16];
    for (int i = 0; i < 16; i++) {
        iv[i] = rand() % 256;
    }

    int key_len = strlen(key);
    int message_len = strlen(message);

    EVP_CIPHER_CTX *enc_ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(enc_ctx, EVP_aes_256_cbc(), NULL, NULL, NULL);
    EVP_EncryptInit_ex(enc_ctx, NULL, NULL, (unsigned char *)key, salt);
    EVP_EncryptInit_ex(enc_ctx, NULL, iv, NULL, NULL);

    int cipher_len = message_len + EVP_MAX_BLOCK_LENGTH;
    unsigned char *cipher = malloc(cipher_len);

    int len;
    EVP_EncryptUpdate(enc_ctx, cipher, &len, (unsigned char *)message, message_len);
    cipher_len = len;
    EVP_EncryptFinal_ex(enc_ctx, cipher + len, &len);
    cipher_len += len;

    EVP_CIPHER_CTX_free(enc_ctx);

    char *result = malloc(sizeof(char) * cipher_len + 24);
    strcpy(result, "Encrypted message: ");
    for (int i = 0; i < 8; i++) {
        sprintf(result, "%s%02x", result, salt[i]);
    }
    for (int i = 0; i < 16; i++) {
        sprintf(result, "%s%02x", result, iv[i]);
    }
    strcat(result, "\n");
    for (int i = 0; i < cipher_len; i++) {
        sprintf(result, "%s%02x", result, cipher[i]);
    }
    strcat(result, "\n");
    return result;
}

char *decrypt(char *cipher_hex, char *key) {
    printf("Decryption time! Let's get that secret message back!\n");

    unsigned char salt[8];
    unsigned char iv[16];
    unsigned char cipher[1024];

    char *token, *p;
    p = cipher_hex;
    token = strsep(&p, "\n");
    for (int i = 0; i < 8; i++) {
        sscanf(token + i * 2, "%2hhX", &salt[i]);
    }
    token = strsep(&p, "\n");
    for (int i = 0; i < 16; i++) {
        sscanf(token + i * 2, "%2hhX", &iv[i]);
    }
    int cipher_len = 0;
    while ((token = strsep(&p, "\n")) != NULL) {
        for (int i = 0; i < strlen(token) / 2; i++) {
            sscanf(token + i * 2, "%2hhX", &cipher[cipher_len]);
            cipher_len++;
        }
    }
    cipher[cipher_len] = '\0';
    cipher_len--;

    int key_len = strlen(key);

    EVP_CIPHER_CTX *dec_ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(dec_ctx, EVP_aes_256_cbc(), NULL, NULL, NULL);
    EVP_DecryptInit_ex(dec_ctx, NULL, NULL, (unsigned char *)key, salt);
    EVP_DecryptInit_ex(dec_ctx, NULL, iv, NULL, NULL);

    unsigned char *plaintext = malloc(cipher_len);
    int len;

    EVP_DecryptUpdate(dec_ctx, plaintext, &len, cipher, cipher_len);
    int plaintext_len = len;
    EVP_DecryptFinal_ex(dec_ctx, plaintext + len, &len);
    plaintext_len += len;

    EVP_CIPHER_CTX_free(dec_ctx);

    char *result = malloc(sizeof(char) * plaintext_len + 19);
    strcpy(result, "Decrypted message: ");
    strcat(result, (char *)plaintext);
    strcat(result, "\n");
    return result;
}

int main() {
    char *message = "Hello, world!";
    char *key = "mysecretkey";

    char *encrypted = encrypt(message, key);
    printf("%s", encrypted);
    free(encrypted);

    char *cipher_hex = "Encrypted message: 45e5421c67c9c155d544ebcf069ce95cd9373a32b0ee3c4e6b2be1216219c0f9\n"
                       "3d19affd204464345f89d01d8a51f598\n";
    char *decrypted = decrypt(cipher_hex, key);
    printf("%s", decrypted);
    free(decrypted);

    return 0;
}