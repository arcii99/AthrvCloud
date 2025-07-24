//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char *argv[]) {
  char input[1024];
  unsigned char hash[SHA256_DIGEST_LENGTH];

  printf("Enter a string to hash: ");
  fgets(input, 1024, stdin);
  input[strcspn(input, "\n")] = 0; // Remove trailing newline

  // Hash the input string using SHA256
  SHA256(input, strlen(input), hash);

  // Print the hashed string in hex format
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x", hash[i]);
  }
  printf("\n");

  return 0;
}