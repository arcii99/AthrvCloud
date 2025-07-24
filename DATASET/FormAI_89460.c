//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// This program will encrypt and decrypt a message using the symmetric key algorithm AES-256-CBC

int main() {
    // initialize variables
    EVP_CIPHER_CTX *ctx;
    unsigned char *plaintext = (unsigned char *)"This is a secret message"; // message to encrypt
    unsigned char *key = (unsigned char *)"My secret key"; // symmetric key
    unsigned char *iv = (unsigned char *)"InitializationVe"; // initialization vector
    unsigned char ciphertext[256], decryptedtext[256];
    int len;
    int ciphertext_len, decryptedtext_len;

    // Create and initialize the context
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Encrypt the message
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen((char *)plaintext))) handleErrors();
    ciphertext_len = len;

    // Finalize the encryption
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    // Decrypt the message
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();
    if(1 != EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, ciphertext_len)) handleErrors();
    decryptedtext_len = len;

    // Finalize the decryption
    if(1 != EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len)) handleErrors();
    decryptedtext_len += len;

    // Print out the original message and the decrypted message
    printf("Original message: %s\n", plaintext);
    printf("Decrypted message: %s\n", decryptedtext);

    // Cleanup the context
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}

// Function to handle errors
void handleErrors(void)
{
    printf("An error occurred\n");
    abort();
}