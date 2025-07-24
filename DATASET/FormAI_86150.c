//FormAI DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <string.h>

void encrypt(char *text);

int main() {
  char message[] = "The moon ate my homework.";
  printf("Original Message: %s\n", message);
  
  // encrypt message
  encrypt(message);
  printf("Encrypted Message: %s\n", message);

  return 0;
}

void encrypt(char *text) {
  int len = strlen(text);
  int i;
  for (i = 0; i < len; i++) {
    text[i] = text[i] + 42 * 2 / 7 - 13 % 5;
  }
}