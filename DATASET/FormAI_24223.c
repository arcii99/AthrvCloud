//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: inquisitive
#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>

int main() {
  char msg[] = "Hello World!"; // message to be hashed
  unsigned char hash[SHA256_DIGEST_LENGTH]; // buffer to store hash value
  SHA256_CTX sha256; // context variable for SHA256

  SHA256_Init(&sha256); // initializing the SHA256 context
  SHA256_Update(&sha256, msg, strlen(msg)); // updating the context with the message
  SHA256_Final(hash, &sha256); // finalizing the SHA256 context and storing the hash value in buffer

  printf("Hash value of '%s'\n", msg);
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x", hash[i]); // printing the hash value in hexadecimal format
  }
  printf("\n");

  return 0;
}