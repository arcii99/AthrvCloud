//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
  int len, outlen;
  const char *message = "Hello World!";
  unsigned char md_value[EVP_MAX_MD_SIZE];
  char encoded[BUF_SIZE], decoded[BUF_SIZE];
  EVP_CIPHER_CTX *ctx;

  // Print the message to be encoded
  printf("Message: %s\n", message);

  // Initialize the context for AES-128 encryption in CBC mode
  ctx = EVP_CIPHER_CTX_new();
  EVP_CIPHER_CTX_init(ctx);
  EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, NULL, NULL);

  // Encrypt the message
  EVP_EncryptUpdate(ctx, encoded, &len, message, strlen(message));
  EVP_EncryptFinal_ex(ctx, encoded + len, &outlen);

  // Print the encoded message
  printf("Encoded Message: ");
  for(int i=0;i<len+outlen;i++) {
    printf("%02x", encoded[i]);
  }
  printf("\n");

  // Initialize the context for AES-128 decryption in CBC mode
  EVP_CIPHER_CTX_reset(ctx);
  EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, NULL, NULL);

  // Decrypt the message
  EVP_DecryptUpdate(ctx, decoded, &len, encoded, len+outlen);
  EVP_DecryptFinal_ex(ctx, decoded + len, &outlen);

  // Terminate the context
  EVP_CIPHER_CTX_free(ctx);

  // Print the decoded message
  decoded[len+outlen] = '\0'; // Null terminate the string
  printf("Decoded Message: %s\n", decoded);

  return 0;
}