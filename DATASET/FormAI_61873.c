//FormAI DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
  unsigned char key[] = "0123456789123456"; // 128-bit encryption key
  unsigned char iv[] = "abcdefghijklmnop"; // 128-bit initialization vector
  unsigned char plaintext[] = "This is a secret message!"; // plaintext message to encrypt
  unsigned char ciphertext[64]; // buffer to hold encrypted message
  unsigned char decrypted[64]; // buffer to hold decrypted message
  
  // create AES encryption context
  AES_KEY aes;
  AES_set_encrypt_key(key, 128, &aes);
  
  // encrypt plaintext message
  AES_cbc_encrypt(plaintext, ciphertext, strlen((char*) plaintext), &aes, iv, AES_ENCRYPT);
  
  // print encrypted message
  printf("Encrypted message: ");
  for (int i = 0; i < strlen((char*) ciphertext); i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");
  
  // create AES decryption context
  AES_set_decrypt_key(key, 128, &aes);
  
  // decrypt ciphertext message
  AES_cbc_encrypt(ciphertext, decrypted, strlen((char*) ciphertext), &aes, iv, AES_DECRYPT);
  
  // print decrypted message
  printf("Decrypted message: %s\n", decrypted);
  
  return 0;
}