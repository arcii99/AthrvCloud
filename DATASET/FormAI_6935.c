//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>

int main() {
    int num_bits = 2048;
    RSA *rsa_keypair;
    char *plain_text = "Hello, World!\n";
    char *encrypted_text;
    char *decrypted_text;
    int encrypted_length;
    int decrypted_length;
    BIGNUM *decrypted_big_num;
    
    // Generate new RSA keypair
    rsa_keypair = RSA_new();
    BIGNUM *public_exponent=BN_new();
    BN_set_word(public_exponent, RSA_F4);
    
    RSA_generate_key_ex(rsa_keypair, num_bits, public_exponent, NULL);
    
    // Encrypt plain text
    encrypted_length = RSA_public_encrypt(strlen(plain_text) + 1, (unsigned char *) plain_text, (unsigned char *) malloc(num_bits / 8), rsa_keypair, RSA_PKCS1_PADDING);
    encrypted_text = (char *) malloc(encrypted_length);
    RSA_public_encrypt(strlen(plain_text) + 1, (unsigned char *) plain_text, (unsigned char *) encrypted_text, rsa_keypair, RSA_PKCS1_PADDING);
    
    // Decrypt encrypted text
    decrypted_big_num = BN_new();
    decrypted_length = RSA_private_decrypt(encrypted_length, (unsigned char *) encrypted_text, (unsigned char *) malloc(num_bits / 8), rsa_keypair, RSA_PKCS1_PADDING);
    decrypted_text = (char *) malloc(decrypted_length);
    RSA_private_decrypt(encrypted_length, (unsigned char *) encrypted_text, (unsigned char *) decrypted_text, rsa_keypair, RSA_PKCS1_PADDING);
    
    // Print results
    printf("Original text: %s", plain_text);
    printf("Encrypted text: %s", encrypted_text);
    printf("Decrypted text: %s", decrypted_text);
    
    // Cleanup
    BN_free(public_exponent);
    RSA_free(rsa_keypair);
    free(encrypted_text);
    free(decrypted_text);
    
    return 0;
}