//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>

#define MESSAGE_SIZE 100

int main()
{
    char message[MESSAGE_SIZE];
    unsigned char encrypted[MESSAGE_SIZE];
    unsigned char decrypted[MESSAGE_SIZE];
    RSA *keypair = RSA_generate_key(1024, 65537, NULL, NULL);
    int encrypted_length, decrypted_length;

    // get message from user
    printf("Enter a message to encrypt: ");
    fgets(message, MESSAGE_SIZE, stdin);

    // encrypt message
    encrypted_length = RSA_public_encrypt(strlen(message), (unsigned char *) message, encrypted, keypair, RSA_PKCS1_OAEP_PADDING);

    // print encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < encrypted_length; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    // decrypt message
    decrypted_length = RSA_private_decrypt(encrypted_length, encrypted, decrypted, keypair, RSA_PKCS1_OAEP_PADDING);

    // print decrypted message
    printf("Decrypted message: %s", decrypted);

    RSA_free(keypair);
    return 0;
}