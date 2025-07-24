//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#define BUFFER_SIZE 1024

int main() {
  char message[BUFFER_SIZE], encrypted[BUFFER_SIZE], decrypted[BUFFER_SIZE];
  unsigned char key[EVP_MAX_KEY_LENGTH];
  unsigned char iv[EVP_MAX_IV_LENGTH];
  EVP_CIPHER_CTX *ctx;

  // Encryption and decryption keys and iv initialization
  memset(key, 0, sizeof(key));
  memset(iv, 0, sizeof(iv));
  strncpy(key, "super_secret_key", 16);
  strncpy(iv, "initialization_v", 16);

  // Message to be encrypted
  printf("Enter the message to be encrypted:\n");
  fgets(message, BUFFER_SIZE, stdin);

  // Initializing context
  ctx = EVP_CIPHER_CTX_new();

  // Encryption
  EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
  EVP_EncryptUpdate(ctx, encrypted, NULL, message, strlen(message));
  EVP_EncryptFinal_ex(ctx, encrypted + strlen(encrypted), NULL);

  printf("Encrypted message:\n%s\n", encrypted);

  // Decryption
  EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
  EVP_DecryptUpdate(ctx, decrypted, NULL, encrypted, strlen(encrypted));
  EVP_DecryptFinal_ex(ctx, decrypted + strlen(decrypted), NULL);

  printf("Decrypted message:\n%s\n", decrypted);

  // Freeing context
  EVP_CIPHER_CTX_free(ctx);

  return 0;
}