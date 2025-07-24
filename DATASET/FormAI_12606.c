//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>

int main() {
  // key should be 128, 192, or 256 bits
  unsigned char key[] = "0123456789abcdef0123456789abcdef";
  unsigned char plaintext[] = "hello world";
  unsigned char encrypted[128];
  unsigned char decrypted[128];
  AES_KEY aes_key;

  AES_set_encrypt_key(key, 128, &aes_key);
  AES_encrypt(plaintext, encrypted, &aes_key);

  printf("Encrypted: %s\n", encrypted);

  AES_set_decrypt_key(key, 128, &aes_key);
  AES_decrypt(encrypted, decrypted, &aes_key);

  printf("Decrypted: %s\n", decrypted);

  return 0;
}