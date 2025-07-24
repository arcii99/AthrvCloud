//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/bn.h>

#define BITS 512

int main()
{
    // Initializing variables
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *phi = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *msg = BN_new();
    BIGNUM *enc = BN_new();
    BIGNUM *dec = BN_new();
    BN_CTX *ctx = BN_CTX_new();

    // Generating random prime numbers p and q
    srand(time(NULL));
    BN_generate_prime_ex(p, BITS, 1, NULL, NULL, NULL);
    BN_generate_prime_ex(q, BITS, 1, NULL, NULL, NULL);

    // Calculating modulus n and totient phi(n)
    BN_mul(n, p, q, ctx);
    BN_sub(p, p, BN_value_one());
    BN_sub(q, q, BN_value_one());
    BN_mul(phi, p, q, ctx);

    // Generating random public key e
    BN_rand_range(e, phi);

    // Calculating private key d
    BN_mod_inverse(d, e, phi, ctx);

    // Encrypting message with public key
    BN_set_word(msg, 1234);
    BN_mod_exp(enc, msg, e, n, ctx);

    // Decrypting message with private key
    BN_mod_exp(dec, enc, d, n, ctx);

    // Printing results
    printf("p: %s\n", BN_bn2dec(p));
    printf("q: %s\n", BN_bn2dec(q));
    printf("n: %s\n", BN_bn2dec(n));
    printf("phi(n): %s\n", BN_bn2dec(phi));
    printf("e: %s\n", BN_bn2dec(e));
    printf("d: %s\n", BN_bn2dec(d));
    printf("Message: %s\n", BN_bn2dec(msg));
    printf("Encrypted Message: %s\n", BN_bn2dec(enc));
    printf("Decrypted Message: %s\n", BN_bn2dec(dec));

    // Freeing memory
    BN_free(p);
    BN_free(q);
    BN_free(n);
    BN_free(phi);
    BN_free(e);
    BN_free(d);
    BN_free(msg);
    BN_free(enc);
    BN_free(dec);
    BN_CTX_free(ctx);

    return 0;
}