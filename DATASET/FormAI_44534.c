//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
    char plaintext[] = "Hello, world!";
    char key[] = "my secret key";
    
    // Set up the encryption context
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, (unsigned char*)"0123456789012345");
    
    // Determine the size of the input, allocate memory for the encrypted output
    int input_len = strlen(plaintext);
    int output_len = input_len + EVP_CIPHER_CTX_block_size(ctx);
    unsigned char *ciphertext = malloc(output_len);
    
    // Encrypt the plaintext
    int ciphertext_len;
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char*)plaintext, input_len);
    int ciphertext_final_len;
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_final_len);
    ciphertext_len += ciphertext_final_len;

    // Print out the encrypted message
    printf("Encrypted message:\n");
    for (int i=0; i < ciphertext_len; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");
    
    // Clean up the encryption context
    EVP_CIPHER_CTX_free(ctx);
    
    return 0;
}