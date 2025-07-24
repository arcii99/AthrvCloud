//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main()
{
    RSA *rsa = RSA_new();
    BIGNUM *bn = BN_new();

    BN_set_word(bn, RSA_F4);
    RSA_generate_key_ex(rsa, 1024, bn, NULL);

    const unsigned char plaintext[] = "My secret message";
    unsigned char ciphertext[RSA_size(rsa)];
    RSA_public_encrypt(strlen(plaintext) + 1, plaintext, ciphertext, rsa, RSA_PKCS1_PADDING);

    unsigned char decryptedtext[RSA_size(rsa)];
    RSA_private_decrypt(RSA_size(rsa), ciphertext, decryptedtext, rsa, RSA_PKCS1_PADDING);
    
    printf("Encrypted message: %s\n", ciphertext);
    printf("Decrypted message: %s\n", decryptedtext);

    RSA_free(rsa);
    BN_free(bn);

    return 0;
}