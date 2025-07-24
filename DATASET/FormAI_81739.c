//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#define KEY_LENGTH  2048
#define PUB_EXP     65537

int main() {
    RSA *keypair;
    keypair = RSA_generate_key(KEY_LENGTH, PUB_EXP, NULL, NULL);
    if (!keypair) {
        fprintf(stderr, "Error generating RSA key pair.\n");
        exit(1);
    }

    const char *pubkey_file = "public_key.pem";
    FILE *pubkey_fp = fopen(pubkey_file, "w");
    if (!PEM_write_RSA_PUBKEY(pubkey_fp, keypair)) {
        fprintf(stderr, "Error writing public key to file.\n");
        exit(1);
    }
    fclose(pubkey_fp);
    printf("Created public key file: %s\n", pubkey_file);

    const char *privkey_file = "private_key.pem";
    FILE *privkey_fp = fopen(privkey_file, "w");
    if (!PEM_write_RSAPrivateKey(privkey_fp, keypair, NULL, NULL, 0, NULL, NULL)) {
        fprintf(stderr, "Error writing private key to file.\n");
        exit(1);
    }
    fclose(privkey_fp);
    printf("Created private key file: %s\n", privkey_file);

    RSA_free(keypair);

    return 0;
}