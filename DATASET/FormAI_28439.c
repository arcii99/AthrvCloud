//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the hashing function
uint32_t cheerfulHash(const char *message, size_t len) {
  uint32_t hash = 0xABCD1234; // Starting hash value
  for (int i = 0; i < len; i++) {
    hash += message[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return hash;
}

int main(int argc, char **argv) {
  if (argc <= 1) {
    printf("Please provide a message to hash!\n");
    return 1;
  }
  char *message = argv[1];
  size_t len = strlen(message);
  uint32_t hash = cheerfulHash(message, len);
  printf("Your cheerful hash is: %08x\n", hash);
  return 0;
}