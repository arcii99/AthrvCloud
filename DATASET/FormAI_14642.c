//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext);
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext);

int main()
{
    // plaintext to be encrypted and decrypted
    unsigned char plaintext[] = "This is a top secret message!";
    
    // the key used for encryption and decryption
    unsigned char key[] = "cryptography101";
    
    // initialization vector
    // note: must be the same for encryption and decryption
    unsigned char iv[] = "encryptionIsFun";
    
    // buffers for encrypted and decrypted messages
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];
    
    // perform encryption
    int ciphertext_len = encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    
    // perform decryption
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0';
    printf("Decrypted text: %s\n", decryptedtext);
    
    return 0;
}

// encrypt using the given plaintext, key, and iv
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    /* Create and initialize the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    /* Initialize the encryption operation */
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    /* Provide the plaintext to be encrypted, and obtain the encrypted output */
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    /* Finalize the encryption */
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// decrypt using the given ciphertext, key, and iv
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;

    /* Create and initialize the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    /* Initialize the decryption operation */
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    /* Provide the ciphertext to be decrypted, and obtain the plaintext output */
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    /* Finalize the decryption */
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// error handling
void handleErrors(void)
{
    printf("An error occurred\n");
    exit(1);
}