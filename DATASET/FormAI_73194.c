//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char str[100];
  int key = 47;
  int i, len;

  printf("Enter the string to be encrypted: ");
  fgets(str, sizeof(str), stdin);

  len = strlen(str);

  for (i = 0; i < len; i++) {
    str[i] = str[i] ^ key; // XOR each character with the key
  }

  printf("Encrypted string: %s\n", str);

  return 0;
}