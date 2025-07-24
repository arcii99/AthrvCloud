//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/rsa.h>
#include<openssl/pem.h>

#define KEY_LENGTH 2048

int main()
{
    char plaintext[50];
    char encrypted[KEY_LENGTH/8];
    char decrypted[KEY_LENGTH/8];
    char public_keyfile[] = "public_key.pem";
    char private_keyfile[] = "private_key.pem";
    RSA *rsa_keypair;

    // Generate RSA key
    rsa_keypair = RSA_generate_key(KEY_LENGTH, RSA_F4, NULL, NULL);
    if(rsa_keypair == NULL){
        printf("RSA Key Generation failed!\n");
        exit(1);
    }

    // Save public key
    FILE *public_key = fopen(public_keyfile, "wb");
    if(public_key == NULL){
        printf("Failed to create public key file!\n");
        exit(1);
    }
    PEM_write_RSAPublicKey(public_key, rsa_keypair);
    fclose(public_key);

    // Save private key
    FILE *private_key = fopen(private_keyfile, "wb");
    if(private_key == NULL){
        printf("Failed to create private key file!\n");
        exit(1);
    }
    PEM_write_RSAPrivateKey(private_key, rsa_keypair, NULL, NULL, 0, NULL, NULL);
    fclose(private_key);

    // Get plaintext and encrypt using public key
    printf("Enter a message to encrypt: ");
    fgets(plaintext, 50, stdin);
    RSA_public_encrypt(strlen(plaintext)+1, (unsigned char*)plaintext, (unsigned char*)encrypted, rsa_keypair, RSA_PKCS1_OAEP_PADDING);

    // Print encrypted message
    printf("Encrypted message: ");
    for(int i=0; i<RSA_size(rsa_keypair); i++){
        printf("%02x", encrypted[i]);
    }

    // Decrypt using private key
    RSA_private_decrypt(RSA_size(rsa_keypair), (unsigned char*)encrypted, (unsigned char*)decrypted, rsa_keypair, RSA_PKCS1_OAEP_PADDING);

    // Print decrypted message
    printf("\nDecrypted message: %s\n", decrypted);

    RSA_free(rsa_keypair);
    return 0;
}