//FormAI DATASET v1.0 Category: modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift);

int main() {
  char message[100];
  int shift;

  // Get message from user
  printf("Enter message to encrypt: ");
  fgets(message, sizeof(message), stdin);

  // Remove newline character from message
  message[strcspn(message, "\n")] = '\0';

  // Get shift value from user
  printf("Enter shift value: ");
  scanf("%d", &shift);

  // Call function to encrypt message
  encrypt(message, shift);

  printf("Encrypted message: %s", message);

  return 0;
}

void encrypt(char *message, int shift) {
  int i = 0;

  while (message[i] != '\0') {
    // Check if current character is a letter
    if (message[i] >= 'a' && message[i] <= 'z') {
      // Apply shift and wrap around if necessary
      message[i] = (message[i] - 'a' + shift) % 26 + 'a';
    } else if (message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = (message[i] - 'A' + shift) % 26 + 'A';
    }

    i++;
  }
}