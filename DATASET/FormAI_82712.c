//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
    // Setting up the encryption context
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    
    // Setting up the key and IV
    char *key = "mysecretkey";
    char *iv = "myiv";
    
    // Setting up the plaintext and the ciphertext buffers
    char *plaintext = "This is a secret message.";
    int plaintext_len = strlen(plaintext) + 1;
    char ciphertext[128];
    int ciphertext_len;
    
    // Encrypting the plaintext
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len,
            plaintext, plaintext_len);
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len);
    
    // Printing out the plaintext and the ciphertext
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", (unsigned char)ciphertext[i]);
    }
    printf("\n");
    
    // Cleaning up the encryption context
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}