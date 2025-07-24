//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

/* This function takes an input string and returns its SHA256 hash */
char* sha256(const char* input) {
  EVP_MD_CTX *mdctx;
  const EVP_MD *md;
  unsigned char *output;
  unsigned int output_len;

  md = EVP_sha256();
  mdctx = EVP_MD_CTX_create();
  EVP_DigestInit_ex(mdctx, md, NULL);
  EVP_DigestUpdate(mdctx, input, strlen(input));
  output_len = EVP_MD_size(md);
  output = (unsigned char*) malloc(output_len);

  EVP_DigestFinal_ex(mdctx, output, &output_len);
  EVP_MD_CTX_destroy(mdctx);

  char* hash = (char*) malloc(output_len * 2 + 1);
  for (int i = 0; i < output_len; i++) {
    sprintf(&hash[i*2], "%02x", (unsigned int) output[i]);
  }
  free(output);

  return hash;
}

int main() {
  printf("Enter a string to hash: ");
  char input[100];
  scanf("%s", input);
  char* hash = sha256(input);
  printf("SHA256 hash of \"%s\": %s\n", input, hash);
  free(hash);
  return 0;
}