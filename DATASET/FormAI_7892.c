//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  // Initial seeds for the LCG algorithm
  unsigned long long x = 0x7f3a4ac275a07840ULL;
  unsigned long long c = 0x54f793af9e22fcbdULL;

  // Input message for encryption
  char message[] = "Hello, World!";
  size_t message_len = strlen(message);

  // Key for encryption
  char key[] = "mysecretkey";
  size_t key_len = strlen(key);

  // XOR the message with the key
  for (size_t i = 0; i < message_len; i++) {
    message[i] ^= key[i % key_len];
  }

  // Encryption using LCG algorithm
  for (size_t i = 0; i < message_len; i++) {
    x = x * 6364136223846793005ULL + c;
    message[i] = message[i] ^ (unsigned char)(x >> 56);
  }

  printf("Encrypted message: %s\n", message);

  // Decryption using LCG algorithm
  for (size_t i = 0; i < message_len; i++) {
    x = x * 6364136223846793005ULL + c;
    message[i] = message[i] ^ (unsigned char)(x >> 56);
  }

  // XOR the decrypted message with the key
  for (size_t i = 0; i < message_len; i++) {
    message[i] ^= key[i % key_len];
  }

  printf("Decrypted message: %s\n", message);

  return 0;
}