//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_KEY_SIZE 256
#define BLOCK_SIZE 16

int main() {
  unsigned char key_hex[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c, 0x2e, 0x8a, 0x39, 0x6b, 0x4b, 0xfe, 0x3d, 0x82, 0x73, 0x5b, 0x61, 0x29, 0x2e, 0x43, 0x6c, 0x82};
  unsigned char iv_hex[] = {0x3a, 0x21, 0x5c, 0x17, 0x22, 0x54, 0x6b, 0x3e, 0x16, 0x98, 0x2a, 0x3e, 0x53, 0x30, 0xfa, 0x54};
  unsigned char plaintext[] = "This is a secret message!";
  
  unsigned char ciphertext[sizeof(plaintext)];
  unsigned char decrypttext[sizeof(plaintext)];
  
  AES_KEY key;
  
  if (AES_set_encrypt_key(key_hex, AES_KEY_SIZE, &key) < 0) {
    fprintf(stderr, "Error: Could not set AES key\n");
    return 1;
  }
  
  AES_cbc_encrypt(plaintext, ciphertext, sizeof(plaintext), &key, iv_hex, AES_ENCRYPT);
  
  printf("Ciphertext (hex): ");
  
  for (int i = 0; i < sizeof(plaintext); i++) {
    printf("%02x", ciphertext[i]);
  }
  
  printf("\n");
  
  if (AES_set_decrypt_key(key_hex, AES_KEY_SIZE, &key) < 0) {
    fprintf(stderr, "Error: Could not set AES key\n");
    return 1;
  }
  
  AES_cbc_encrypt(ciphertext, decrypttext, sizeof(ciphertext), &key, iv_hex, AES_DECRYPT);
  
  printf("Plaintext: %s\n", decrypttext);
  
  return 0;
}