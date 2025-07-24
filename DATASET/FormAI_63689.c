//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/bn.h>

/* Generate key pair */
void generate_key_pair(EVP_PKEY **priv_key, EVP_PKEY **pub_key) {
    EVP_PKEY_CTX *ctx;
    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    EVP_PKEY_keygen_init(ctx);
    EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 2048);
    EVP_PKEY_keygen(ctx, priv_key);
    EVP_PKEY_keygen(ctx, pub_key);
    EVP_PKEY_CTX_free(ctx);
}

int main() {
    EVP_PKEY *priv_key = NULL;  /* Private key */
    EVP_PKEY *pub_key = NULL;   /* Public key */

    RAND_load_file("/dev/urandom", 128);

    generate_key_pair(&priv_key, &pub_key);

    /* Use the keys for encryption and decryption */
    // ...

    EVP_PKEY_free(pub_key);
    EVP_PKEY_free(priv_key);

    return 0;
}