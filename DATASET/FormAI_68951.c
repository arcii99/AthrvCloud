//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_LENGTH 100 // Maximum length of password

// Function to encrypt password using AES-256 encryption
void encrypt_password(char *password)
{
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char cipher[MAX_LENGTH + EVP_MAX_BLOCK_LENGTH];
    size_t password_length = strlen(password) + 1;
    size_t block_length;
    int ciphertext_length;

    // Set encryption key and initialization vector
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_set_padding(ctx, 1);
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Encrypt password
    EVP_EncryptUpdate(ctx, cipher, &ciphertext_length, password, password_length);
    EVP_EncryptFinal_ex(ctx, cipher + ciphertext_length, &block_length);

    // Print encrypted password
    printf("Encrypted Password: ");
    for (int i = 0; i < (ciphertext_length + block_length); i++) {
        printf("%02x", cipher[i]);
    }
    printf("\n");

    EVP_CIPHER_CTX_free(ctx);
}

int main()
{
    char password[MAX_LENGTH];

    // Get password from user
    printf("Enter password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;

    // Encrypt password
    encrypt_password(password);

    return 0;
}