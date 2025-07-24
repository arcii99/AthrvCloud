//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>

#define KEY_LENGTH 2048

int main() {

    RSA *keypair;
    BIGNUM *e, *d, *n;
    char *pub_key_str;
    char *priv_key_str;
    int len;

    // initialize variables
    keypair = RSA_new();
    e = BN_new();
    d = BN_new();
    n = BN_new();

    // set exponent and generate public and private keys
    BN_set_word(e, RSA_F4);
    RSA_generate_key_ex(keypair, KEY_LENGTH, e, NULL);

    // retrieve public and private key values
    RSA_get0_key(keypair, &n, &e, &d);
    len = BN_num_bits(n);

    // convert keys to printable strings
    pub_key_str = BN_bn2hex(e);
    priv_key_str = BN_bn2hex(d);

    // output keys
    printf("Public Key: %s\n", pub_key_str);
    printf("Private Key: %s\n", priv_key_str);

    // clean up
    RSA_free(keypair);
    BN_free(n);
    BN_free(e);
    BN_free(d);
    OPENSSL_free(pub_key_str);
    OPENSSL_free(priv_key_str);

    return 0;
}