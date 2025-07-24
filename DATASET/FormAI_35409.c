//FormAI DATASET v1.0 Category: modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "braveencryption"
#define BLOCK_SIZE 16

char *encrypt(char *plaintext);
char *decrypt(char *ciphertext);

int main() {
  char *plaintext = "This is a brave encryption example!";
  char *ciphertext = encrypt(plaintext);
  char *decrypted_plaintext = decrypt(ciphertext);
  
  printf("\nPlaintext: %s\n", plaintext);
  printf("\nEncrypted ciphertext: %s\n", ciphertext);
  printf("\nDecrypted plaintext: %s\n", decrypted_plaintext);

  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}

char *encrypt(char *plaintext) {
  int plaintext_len = strlen(plaintext);
  int padded_len = plaintext_len;
  while(padded_len % BLOCK_SIZE != 0) {
    padded_len++;
  }

  char *padded_plaintext = (char *)calloc(padded_len + 1, sizeof(char));
  strcpy(padded_plaintext, plaintext);

  for(int i = plaintext_len; i < padded_len; i++) {
    padded_plaintext[i] = ' ';
  }
  
  char *ciphertext = (char *)calloc(padded_len + 1, sizeof(char));

  for (int i = 0; i < padded_len; i += BLOCK_SIZE) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      ciphertext[i+j] = ((padded_plaintext[i+j] ^ KEY[j]) + KEY[j]) % 256;
    }
  }

  free(padded_plaintext);
  return ciphertext;
}

char *decrypt(char *ciphertext) {
  int ciphertext_len = strlen(ciphertext);
  char *decrypted_plaintext = (char *)calloc(ciphertext_len + 1, sizeof(char));

  for (int i = 0; i < ciphertext_len; i += BLOCK_SIZE) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      decrypted_plaintext[i+j] = ((ciphertext[i+j] - KEY[j]) ^ KEY[j]);
    }
  }

  int plaintext_len = strlen(decrypted_plaintext);

  while(decrypted_plaintext[plaintext_len-1] == ' ') {
    plaintext_len--;
  }

  decrypted_plaintext[plaintext_len] = '\0';
  
  return decrypted_plaintext;
}