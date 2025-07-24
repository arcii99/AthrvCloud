//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

int main()
{
    // Initialize plaintext and encryption key values
    unsigned char plain_text[] = "Hello World!";
    unsigned char encrypt_key[] = "thisisaeskey1234";

    // Initialize cipher and iv values
    unsigned char iv[] = {0x24, 0x6f, 0x74, 0x68, 0x65, 0x72, 0x74, 0x6f, 0x6f, 0x6c, 0x6f, 0x6e, 0x67, 0x68, 0x6f, 0x72};
    unsigned char ciphertext[sizeof(plain_text)];

    // Initialize the AES cipher context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, encrypt_key, iv);

    // Encrypt the plaintext
    int len = strlen((const char*) plain_text);
    int out_len1 = 0;
    int out_len2 = 0;
    EVP_EncryptUpdate(ctx, ciphertext, &out_len1, plain_text, len);
    EVP_EncryptFinal_ex(ctx, ciphertext + out_len1, &out_len2);

    // Print the encrypted text
    printf("Encrypted Text: ");
    for (int i = 0; i < out_len1 + out_len2; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Reset the cipher context
    EVP_CIPHER_CTX_reset(ctx);

    // Initialize the decryption key value
    unsigned char decrypt_key[] = "thisisaeskey1234";

    // Initialize the AES cipher context for decryption
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, decrypt_key, iv);

    // Decrypt the ciphertext
    int out_len3 = 0;
    int out_len4 = 0;
    unsigned char decrypted_text[sizeof(plain_text)];
    EVP_DecryptUpdate(ctx, decrypted_text, &out_len3, ciphertext, out_len1 + out_len2);
    EVP_DecryptFinal_ex(ctx, decrypted_text + out_len3, &out_len4);

    // Print the decrypted text
    printf("Decrypted Text: %s\n", decrypted_text);

    // Cleanup
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}