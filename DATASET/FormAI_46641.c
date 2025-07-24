//FormAI DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

char* encrypt(char* str) {
  char* result = malloc(strlen(str) + 1);
  int len = strlen(KEY);
  int i, j, k;
  for (i = 0; str[i] != '\0'; i++) {
    j = i % len;
    k = i / len;
    result[i] = KEY[j] ^ str[i] ^ k;
  }
  result[i] = '\0';
  return result;
}

char* decrypt(char* str) {
  char* result = malloc(strlen(str) + 1);
  int len = strlen(KEY);
  int i, j, k;
  for (i = 0; str[i] != '\0'; i++) {
    j = i % len;
    k = i / len;
    result[i] = KEY[j] ^ str[i] ^ k;
  }
  result[i] = '\0';
  return result;
}

int main() {
  char plaintext[] = "Hello, world!";
  printf("Plaintext: %s\n", plaintext);

  char* ciphertext = encrypt(plaintext);
  printf("Ciphertext: %s\n", ciphertext);

  char* decrypted = decrypt(ciphertext);
  printf("Decrypted: %s\n", decrypted);

  free(ciphertext);
  free(decrypted);

  return 0;
}