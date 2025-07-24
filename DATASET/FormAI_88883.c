//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#define KEY_LENGTH  2048

int main() {
    int ret = 0;
    RSA *keypair = RSA_new();
    BIGNUM *bne = BN_new();
    BIO *bp_public = NULL, *bp_private = NULL;
    char *pubkey = "public.pem";
    char *privkey = "private.pem";
    unsigned long e = RSA_F4;

    if (!BN_set_word(bne, e)) {
        ret = 1;
        goto free_all;
    }

    if (!RSA_generate_key_ex(keypair, KEY_LENGTH, bne, NULL)) {
        ret = 1;
        goto free_all;    
    }

    bp_public = BIO_new_file(pubkey, "w+");
    if(!PEM_write_bio_RSAPublicKey(bp_public, keypair)){
        ret = 1;
        goto free_all;    
    }

    bp_private = BIO_new_file(privkey, "w+");
    if(!PEM_write_bio_RSAPrivateKey(bp_private, keypair, NULL, NULL, 0, NULL, NULL)){
        ret = 1;
        goto free_all;    
    }

free_all:

    BIO_free_all(bp_public);
    BIO_free_all(bp_private);
    RSA_free(keypair);
    BN_free(bne);

    return ret;
}