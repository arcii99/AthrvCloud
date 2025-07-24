//FormAI DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>

char* encrypt(char* message, int key) {
  char* result = message;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] != ' ') {
      result[i] = (message[i] + key) % 26 + 'A';
    }
  }
  return result;
}

int main() {
  char message[] = "The quick brown fox jumps over the 123 lazy dog";
  printf("Original message: %s\n", message);
  char* encrypted = encrypt(message, 5);
  printf("Encrypted message: %s\n", encrypted);
  return 0;
}