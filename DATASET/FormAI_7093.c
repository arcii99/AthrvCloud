//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_LEN 32 // Setting key length to 32 bytes for AES-256 encryption
#define IV_LEN 16 // Setting initialization vector length to 16 bytes

void handleErrors(void)
{
  printf("An error occurred. Exiting program...\n");
  exit(1);
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext)
{
  EVP_CIPHER_CTX *ctx;

  int len;

  int ciphertext_len;

  if (!(ctx = EVP_CIPHER_CTX_new()))
    handleErrors();

  if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    handleErrors();

  if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
    handleErrors();
  ciphertext_len = len;

  if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
    handleErrors();
  ciphertext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext)
{
  EVP_CIPHER_CTX *ctx;

  int len;

  int plaintext_len;

  if (!(ctx = EVP_CIPHER_CTX_new()))
    handleErrors();

  if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    handleErrors();

  if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
    handleErrors();
  plaintext_len = len;

  if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
    handleErrors();
  plaintext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return plaintext_len;
}

int main()
{
  unsigned char *key = (unsigned char *)"01234567890123456789012345678901"; // Setting key to 32 byte string
  unsigned char *iv = (unsigned char *)"0123456789012345"; // Setting initialization vector to 16 byte string
  unsigned char plaintext[] = "This is a test message."; // Setting plaintext message
  unsigned char ciphertext[128]; // Setting size for ciphertext output buffer
  unsigned char decryptedtext[128]; // Setting size for decrypted text output buffer

  int decryptedtext_len, ciphertext_len;

  ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv,
    ciphertext);

  printf("Ciphertext is:\n");
  BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len); // Outputting ciphertext in hex format for easy reading

  decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv,
    decryptedtext);

  decryptedtext[decryptedtext_len] = '\0';

  printf("Decrypted text is:\n");
  printf("%s\n", decryptedtext); // Outputting decrypted text

  return 0;
}