//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: excited
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
  char input_string[100];
  printf("Enter a string to hash: \n");
  scanf("%s", input_string);

  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256(input_string, strlen(input_string), hash);

  printf("The SHA256 hash of %s is: ", input_string);
  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x", hash[i]);
  }
  printf("\n");
  return 0;
}