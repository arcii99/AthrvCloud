//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <string.h>

void encrypt(char* message, char* key);

int main() {
  char message[100] = "Hello World";
  char key[10] = "secretkey";

  printf("Original Message: %s\n", message);

  encrypt(message, key);

  printf("Encrypted Message: %s\n", message);

  return 0;
}

void encrypt(char* message, char* key) {
  int message_len = strlen(message);
  int key_len = strlen(key);

  for (int i = 0; i < message_len; i++) {
    message[i] ^= key[i % key_len];
  }
}