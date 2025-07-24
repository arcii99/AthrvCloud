//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>
#include<string.h>
#include<openssl/rsa.h>
#include<openssl/pem.h>

#define RSA_KEY_LENGTH 2048

int main(){
    RSA *keypair = RSA_new();
    BIGNUM *e = BN_new();

    BN_set_word(e, RSA_F4); // sets e to 65537 (a commonly used value for RSA encryption)

    RSA_generate_key_ex(keypair, RSA_KEY_LENGTH, e, NULL); // generates public/private key pair

    unsigned char plaintext[256] = "This is some plaintext data for encryption using RSA";
    unsigned char ciphertext[256] = {0};
    int ciphertext_len = 0;

    ciphertext_len = RSA_public_encrypt(strlen(plaintext), plaintext, ciphertext, keypair, RSA_PKCS1_OAEP_PADDING); // encrypts plaintext with public key using OAEP padding

    printf("Ciphertext: ");
    for(int i=0; i<ciphertext_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    unsigned char decryptedtext[256] = {0};
    int decryptedtext_len = 0;

    decryptedtext_len = RSA_private_decrypt(ciphertext_len, ciphertext, decryptedtext, keypair, RSA_PKCS1_OAEP_PADDING); // decrypts ciphertext with private key using OAEP padding

    printf("Decrypted text: %s\n", decryptedtext);

    RSA_free(keypair);
    BN_free(e);

    return 0;
}