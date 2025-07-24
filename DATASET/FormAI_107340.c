//FormAI DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext) {

  AES_KEY aes_key;
  AES_set_encrypt_key(key, 128, &aes_key);
  AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv, AES_ENCRYPT);
}

int main() {

  unsigned char *key = (unsigned char *)"0123456789012345"; // 16-byte key
  unsigned char *iv = (unsigned char *)"0123456789012345";  // 16-byte initialization vector
  unsigned char plaintext[] = "Hello, world!";              // plaintext message to encrypt
  int plaintext_len = strlen((char *)plaintext);
  int ciphertext_len = plaintext_len + AES_BLOCK_SIZE;
  unsigned char ciphertext[ciphertext_len];

  // Encrypt the plaintext
  encrypt(plaintext, plaintext_len, key, iv, ciphertext);

  // Print out the ciphertext as hex bytes
  for (int i = 0; i < ciphertext_len; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  return 0;
}