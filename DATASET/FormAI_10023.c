//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* string, int key) {
  char* encrypted = (char*) malloc(sizeof(char) * strlen(string));
  int i;
  for (i = 0; i < strlen(string); i++) {
    encrypted[i] = (string[i] + key) % 127;
  }
  encrypted[i] = '\0';
  return encrypted;
}

char* decrypt(char* encrypted, int key) {
  char* decrypted = (char*) malloc(sizeof(char) * strlen(encrypted));
  int i;
  for (i = 0; i < strlen(encrypted); i++) {
    decrypted[i] = (encrypted[i] - key + 127) % 127;
  }
  decrypted[i] = '\0';
  return decrypted;
}

int main() {
  printf("Welcome to the encryption program!\n\n");
  printf("Please provide the string to encrypt: ");
  char string[256];
  scanf("%s", string);
  printf("Please provide the key: ");
  int key;
  scanf("%d", &key);

  char* encrypted = encrypt(string, key);
  printf("\nEncrypted string: %s\n", encrypted);
  free(encrypted);

  char* decrypted = decrypt(encrypted, key);
  printf("Decrypted string: %s\n", decrypted);
  free(decrypted);

  printf("\nThank you for using the encryption program!\n");
  return 0;
}