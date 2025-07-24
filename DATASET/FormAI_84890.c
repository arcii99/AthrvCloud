//FormAI DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 128

/* Encrypt/Decrypt the message using AES with a given key */
int aes_crypto(unsigned char *key, unsigned char *iv, int do_encrypt, unsigned char *in_data, int in_len, unsigned char *out_data) {
  AES_KEY aes_key;
  AES_set_encrypt_key(key, KEY_SIZE, &aes_key);
  
  if (in_len % AES_BLOCK_SIZE != 0) {
    printf("Error: Input data must be multiple of block size\n");
    return -1;
  }

  AES_cbc_encrypt(in_data, out_data, in_len, &aes_key, iv, do_encrypt);
  return 0;
}

int main() {
  unsigned char key[16] = "secret_key";
  unsigned char iv[AES_BLOCK_SIZE] = "1234567890123456";
  unsigned char in_data[64] = "Hello! This is a test message";
  unsigned char out_data[128];
  int in_len = strlen((const char *)in_data);
  int do_encrypt = 1;

  aes_crypto(key, iv, do_encrypt, in_data, in_len, out_data);

  printf("Input Data: %s\n", in_data);
  printf("Encrypted Data: ");

  for (int i = 0; i < in_len; ++i) {
    printf("%02x", out_data[i]);
  }

  do_encrypt = 0;

  aes_crypto(key, iv, do_encrypt, out_data, in_len, in_data);

  printf("\nDecrypted Data: %s\n", in_data);

  return 0;
}