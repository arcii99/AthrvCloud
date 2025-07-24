//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mathematical
#include <stdio.h>
#include <stdint.h>

uint32_t rotate_left(uint32_t value, uint32_t shift) {
  return (value << shift) | (value >> (32 - shift));
}

uint32_t crypto_hash(const void *message, size_t len) {
  const uint8_t *data = (const uint8_t *)message;
  uint32_t hash = 0xdeadbeef;
  size_t i;

  for (i = 0; i < len; i++) {
    hash += data[i];
    hash = rotate_left(hash, 23);
    hash *= 0xdeadbeef;
    hash ^= hash >> 15;
  }

  return hash;
}

int main() {
  const char message[] = "Hello, world!";
  uint32_t hash = crypto_hash(message, sizeof(message) - 1);
  printf("Hash: %08x\n", hash);

  return 0;
}