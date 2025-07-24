//FormAI DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int key) {
  for(int i = 0; i < strlen(str); i++) {
    str[i] += key;
  }
}

void decrypt(char *str, int key) {
  for(int i = 0; i < strlen(str); i++) {
    str[i] -= key;
  }
}

int main() {
  char str[100];
  int key;

  printf("Enter a string to encrypt: ");
  fgets(str, sizeof(str), stdin);

  printf("Enter a key to encrypt with: ");
  scanf("%d", &key);

  encrypt(str, key);

  printf("Encrypted string: %s", str);

  decrypt(str, key);

  printf("Decrypted string: %s", str);

  return 0;
}