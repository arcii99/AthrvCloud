//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main() {
    RSA *rsa_key_pair = RSA_new();
    int bits = 2048;
    unsigned long e = RSA_F4;
    BIGNUM *exp = BN_new();

    BN_set_word(exp, e);

    RSA_generate_key_ex(rsa_key_pair, bits, exp, NULL);

    RSA_print_fp(stdout, rsa_key_pair, 0);

    RSA_free(rsa_key_pair);
    BN_free(exp);

    return 0;
}