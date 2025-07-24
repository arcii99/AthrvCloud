//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 16

void encrypt_decrypt(const unsigned char *input, int length, unsigned char *key, unsigned char *iv) {
    EVP_CIPHER_CTX *context = EVP_CIPHER_CTX_new();
    int output_length, final_length;
    unsigned char output[length + BLOCK_SIZE];

    // Initialize encryption/decryption context with the cipher type, key and iv
    EVP_CipherInit_ex(context, EVP_aes_128_cbc(), NULL, key, iv, 1);

    // Encrypt/decrypt the data
    EVP_CipherUpdate(context, output, &output_length, input, length);

    // Finalize the encryption/decryption process and retrieve any remaining data
    EVP_CipherFinal_ex(context, output + output_length, &final_length);

    // Print the output data
    printf("Output: ");
    for (int i = 0; i < output_length + final_length; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    EVP_CIPHER_CTX_free(context);
}

int main() {
    unsigned char input[] = "Hello World!"; // input data to be encrypted
    int length = strlen(input);

    unsigned char key[] = "1234567812345678"; // 16-byte key
    unsigned char iv[] = "1234567812345678"; // 16-byte iv

    encrypt_decrypt(input, length, key, iv);

    return 0;
}