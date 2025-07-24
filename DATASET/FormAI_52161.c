//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTR(x,n) ((x >> n) | (x << (32 - n)))

uint32_t hash(const char *key) {
  uint32_t h = 0;

  for(int i = 0; i < strlen(key); i++) {
    h = h ^ ((ROTR(h, 5) + key[i] + ROTR(h, 1)) % UINT32_MAX);
  }

  return h;
}

int main() {
  char str[100];
  printf("Enter a string to generate its cryptographic hash: ");
  scanf("%s", str);

  uint32_t hashed = hash(str);
  printf("The cryptographic hash is: %u\n", hashed);

  return 0;
}