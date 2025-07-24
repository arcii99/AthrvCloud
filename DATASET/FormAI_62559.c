//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main() {

    RSA *rsa = NULL;
    BIGNUM *e_value = BN_new();
    BIO *bio_err = NULL;
    char *msg = "Hello World!";
    unsigned char *encrypted_msg = NULL, *decrypted_msg = NULL;
    int rsa_len, encrypted_msg_len, decrypted_msg_len, padding = RSA_PKCS1_PADDING;

    // Generate RSA Key Pair
    rsa = RSA_new();
    BN_set_word(e_value, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, e_value, NULL);

    rsa_len = RSA_size(rsa); // Get RSA key size

    // Encrypt a message
    encrypted_msg = (unsigned char *) malloc(rsa_len);
    encrypted_msg_len = RSA_public_encrypt(strlen(msg) + 1, (unsigned char *)msg, encrypted_msg, rsa, padding);

    // Decrypt the encrypted message
    decrypted_msg = (unsigned char *) malloc(rsa_len);
    decrypted_msg_len = RSA_private_decrypt(encrypted_msg_len, encrypted_msg, decrypted_msg, rsa, padding);

    // Output the Original, Encrypted and Decrypted Messages
    printf("Original Message: %s\n", msg);
    printf("Encrypted Message: ");
    for (int i = 0; i < encrypted_msg_len; i++) {
        printf("%02x", encrypted_msg[i]);
    }
    printf("\n");
    printf("Decrypted Message: %s\n", decrypted_msg);

    RSA_free(rsa);
    BN_free(e_value);
    free(encrypted_msg);
    free(decrypted_msg);

    return 0;
}