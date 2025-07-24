//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_KEY_LENGTH 64
#define MAX_IV_LENGTH 32

// Function to encrypt a plain text using a key and an initialization vector
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext) 
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    // Create and initialize the context object
    if(!(ctx = EVP_CIPHER_CTX_new())) 
        return -1;

    // Initialize the encryption operation by setting the cipher, key and iv
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return -1;

    // Encrypt the plaintext and put the result in ciphertext
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        return -1;
    ciphertext_len = len;

    // Finalize the encryption operation
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        return -1;
    ciphertext_len += len;

    // Free the context
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt a ciphertext using a key and an initialization vector
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext) 
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    // Create and initialize the context object
    if(!(ctx = EVP_CIPHER_CTX_new()))
        return -1;

    // Initialize the decryption operation by setting the cipher, key and iv
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return -1;

    // Decrypt the ciphertext and put the result in plaintext
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        return -1;
    plaintext_len = len;

    // Finalize the decryption operation
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        return -1;
    plaintext_len += len;

    // Free the context
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(int argc, char *argv[]) 
{
    unsigned char plaintext[1024] = "This is a plain text message"; // Define the input plaintext

    unsigned char key[MAX_KEY_LENGTH] = "This is the secret key"; // Define the key

    unsigned char iv[MAX_IV_LENGTH] = "This is the IV"; // Define the initialization vector

    unsigned char ciphertext[1024];

    unsigned char decryptedtext[1024];

    int decryptedtext_len, ciphertext_len;

    // Encrypt the plaintext using the key and an initialization vector
    ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

    // Print the ciphertext in hexadecimal format
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++) 
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Decrypt the ciphertext using the key and an initialization vector
    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    // Add a null terminator to the decrypted text
    decryptedtext[decryptedtext_len] = '\0';

    // Print the decrypted text
    printf("Decrypted text is:\n");
    printf("%s\n", decryptedtext);

    return 0;
}