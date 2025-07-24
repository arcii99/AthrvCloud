//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mind-bending
#include <stdio.h>
#include <openssl/rsa.h>

int main(){
    RSA* rsa = RSA_generate_key(2048, 65537, NULL, NULL);

    // Generate a random number
    unsigned char in[256];
    RAND_bytes(in, 256);

    // Get the maximum output size for encryption
    int max_out_size = RSA_size(rsa);
    unsigned char out[max_out_size];

    // Encrypt with RSA_public_encrypt
    int out_len = RSA_public_encrypt(256, in, out, rsa, RSA_PKCS1_OAEP_PADDING);

    printf("Encrypted message: ");
    for (int i = 0; i < out_len; i++) {
        printf("%02X", out[i]);
    }
    printf("\n");

    // Decrypt with RSA_private_decrypt
    unsigned char dec[256];
    int dec_len = RSA_private_decrypt(out_len, out, dec, rsa, RSA_PKCS1_OAEP_PADDING);

    printf("Decrypted message: ");
    for (int i = 0; i < dec_len; i++) {
        printf("%c", dec[i]);
    }
    printf("\n");

    RSA_free(rsa);
    return 0;
}