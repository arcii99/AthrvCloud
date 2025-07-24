//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s [string]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *msg = argv[1];
  unsigned char hash[SHA256_DIGEST_LENGTH];

  SHA256_CTX sha_ctx;
  SHA256_Init(&sha_ctx);
  SHA256_Update(&sha_ctx, msg, strlen(msg));
  SHA256_Final(hash, &sha_ctx);

  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x ", hash[i]);
  }
  printf("\n");
  
  return EXIT_SUCCESS;
}