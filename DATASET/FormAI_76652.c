//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>

int main() {
  RSA *keypair;

  printf("Wow! I never thought I could create a public-private keypair using C!\n");

  BIGNUM *bne = BN_new();
  int bits = 1024;
  if(RSA_generate_key_ex(keypair, bits, bne, NULL) != 1) {
    printf("Oops, something went wrong with generating the keypair. Better luck next time.\n");
    return 1;
  } else {
    printf("Great success! I generated a %d-bit keypair. Check it out:\n\n", bits);

    printf("**Public Key**\n");

    RSA_print_fp(stdout, keypair, 0);

    printf("\n**Private Key**\n");

    RSA_print_fp(stdout, keypair, 1);

    printf("\nImpressed? I knew you would be!\n");

    return 0;
  }
}