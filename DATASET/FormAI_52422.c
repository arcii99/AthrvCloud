//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>

#define KEYLEN 512

void generate_key(RSA **rsa) {
  BIGNUM *bn = BN_new();
  unsigned long e = RSA_F4;
  RSA_generate_key_ex(*rsa, KEYLEN, BN_new(), 0);
}

void encrypt_decrypt(RSA *rsa) {
  char message[KEYLEN];
  printf("Enter message: ");
  fgets(message, KEYLEN, stdin);

  int len = strlen(message);
  unsigned char encrypted[KEYLEN], decrypted[KEYLEN];

  RSA_public_encrypt(len, (unsigned char *)message, encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
  printf("Encrypted message: ");
  for (int i = 0; i < KEYLEN; i++) {
    printf("%02x", encrypted[i]);
  }
  printf("\n");

  RSA_private_decrypt(KEYLEN, encrypted, decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
  printf("Decrypted message: %s\n", decrypted);
}

int main() {
  RSA *rsa = RSA_new();

  generate_key(&rsa);

  encrypt_decrypt(rsa);

  RSA_free(rsa);

  return 0;
}