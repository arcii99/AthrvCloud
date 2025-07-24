//FormAI DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_LEN 1024

int main()
{
    // Initializing the necessary variables
    int msg_size, cipher_size, key_size, iv_size;
    unsigned char key[] = "01234567890123456789012345678901";
    unsigned char iv[] = "0123456789012345";
    unsigned char plaintext[MAX_LEN];
    unsigned char ciphertext[MAX_LEN + EVP_MAX_BLOCK_LENGTH];
    unsigned char decrypted_text[MAX_LEN];

    // Getting the plaintext from the user
    printf("Enter the plaintext to encrypt:\n");
    fgets(plaintext, MAX_LEN, stdin);
    msg_size = strlen(plaintext);

    // Initializing the encryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Encrypting the plaintext
    EVP_EncryptUpdate(ctx, ciphertext, &cipher_size, plaintext, msg_size);
    EVP_EncryptFinal_ex(ctx, ciphertext + cipher_size, &cipher_size);

    // Printing the ciphertext
    printf("The ciphertext is:\n");
    for (int i = 0; i < cipher_size; i++) {
        printf("%02x", ciphertext[i]);
    }

    // Initializing the decryption context
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Decrypting the ciphertext
    EVP_DecryptUpdate(ctx, decrypted_text, &msg_size, ciphertext, cipher_size);
    EVP_DecryptFinal_ex(ctx, decrypted_text + msg_size, &msg_size);

    // Printing the decrypted plaintext
    printf("\nThe decrypted text is: %s\n", decrypted_text);

    // Freeing the resources
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}