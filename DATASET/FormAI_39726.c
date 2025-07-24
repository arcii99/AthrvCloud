//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void sha256(unsigned char *input, unsigned char *output) {
  // Initializing variables to hold the hash result
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, input, strlen(input));
  SHA256_Final(output, &ctx);
}

int main() {
  // Initializing variables
  unsigned char input[] = "Hello world!";
  unsigned char output[SHA256_DIGEST_LENGTH];

  // Calling sha256 function
  sha256(input, output);

  // Printing the hash result
  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x", output[i]);
  }
  printf("\n");
  return 0;
}