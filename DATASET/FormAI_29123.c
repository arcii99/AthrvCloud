//FormAI DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to shift the characters in a given string by a given amount
char *shift_string(char *str, int shift) {
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    // Shift each character by the given amount
    str[i] = (str[i] - 'a' + shift) % 26 + 'a';
  }
  return str;
}

int main() {
  // Declare variables for the message to encrypt and the key to use
  char message[100], key[100];
  int keynum;

  // Get the message to encrypt and the key from the user
  printf("Enter a message to encrypt: ");
  fgets(message, sizeof(message), stdin);
  printf("Enter a key (number of shifts): ");
  scanf("%d", &keynum);
  // Ignore any remaining characters in the input stream
  while (getchar() != '\n');

  // Encrypt the message using the key
  shift_string(message, keynum);

  // Print the encrypted message
  printf("Encrypted message: %s\n", message);

  // Decrypt the message using the same key
  shift_string(message, 26 - keynum);

  // Print the decrypted message
  printf("Decrypted message: %s\n", message);

  return 0;
}