//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>

int main(int argc, char** argv) {
  char* key = "mysecretkey";
  char* data = "mydata";
  unsigned char* digest;
  unsigned int digest_len;
  int i;

  digest = HMAC(EVP_sha256(), key, strlen(key), (unsigned char*) data, strlen(data), NULL, &digest_len);

  printf("HMAC digest: ");
  for (i = 0; i < digest_len; i++) {
    printf("%02x", digest[i]);
  }
  printf("\n");

  free(digest);
  return 0;
}