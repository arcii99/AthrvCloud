//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

void encrypt(char *str, int key) {
  int length = strlen(str);
  for(int i = 0; i < length; i++) {
    str[i] = str[i] + key;
  }
}

void decrypt(char *str, int key) {
  int length = strlen(str);
  for(int i = 0; i < length; i++) {
    str[i] = str[i] - key;
  }
}

int main() {
  char message[50];
  int key;

  printf("Enter message to encrypt: ");
  fgets(message, 50, stdin);

  printf("Enter encryption key: ");
  scanf("%d", &key);

  encrypt(message, key);
  printf("Encrypted message: %s\n", message);

  decrypt(message, key);
  printf("Decrypted message: %s\n", message);

  return 0;
}