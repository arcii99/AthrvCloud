//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  printf("Welcome to the surreal encryption program!\n");
  // Prompt user for input
  char input[100];
  printf("What message would you like to encrypt?\n");
  fgets(input, 100, stdin);

  // Generate a random key
  int key = rand() % 26;
  printf("Your randomly generated key is: %d\n", key);

  // Encrypt the message using the key
  for (int i = 0; input[i] != '\0'; ++i) {
    char c = input[i];
    // Only encrypt alphabetical characters
    if (c >= 'a' && c <= 'z') {
      c = (c - 'a' + key) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
      c = (c - 'A' + key) % 26 + 'A';
    }
    input[i] = c;
  }

  printf("Your encrypted message is: %s\n", input);

  // Decrypt the message using the key
  for (int i = 0; input[i] != '\0'; ++i) {
    char c = input[i];
    // Only decrypt alphabetical characters
    if (c >= 'a' && c <= 'z') {
      c = (c - 'a' + (26 - key)) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
      c = (c - 'A' + (26 - key)) % 26 + 'A';
    }
    input[i] = c;
  }

  printf("Your decrypted message is: %s\n", input);

  return 0;
}