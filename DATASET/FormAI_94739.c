//FormAI DATASET v1.0 Category: Encryption ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

int main() {
  char message[MAX_LEN], key[MAX_LEN], encrypted[MAX_LEN];
  int i, j;

  printf("Enter the message: ");
  fgets(message, MAX_LEN, stdin);

  printf("Enter the key: ");
  fgets(key, MAX_LEN, stdin);

  for (i = 0; message[i] != '\0'; i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      j = message[i] - 'a';
      encrypted[i] = key[j];
    } else if (message[i] >= 'A' && message[i] <= 'Z') {
      j = message[i] - 'A';
      encrypted[i] = key[j];
    } else {
      encrypted[i] = message[i];
    }
  }

  printf("Encrypted message: %s", encrypted);

  return 0;
}