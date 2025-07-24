//FormAI DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[100];
  int key = 15;
  int i = 0;

  printf("Enter a message to encrypt: ");
  fgets(message, 100, stdin);

  while (message[i] != '\0') {  // loop until the end of the message
    if (message[i] >= 'a' && message[i] <= 'z') {
      // shift the letter by key positions
      message[i] = ((message[i] - 'a') + key) % 26 + 'a';
    }
    else if (message[i] >= 'A' && message[i] <= 'Z') {
      // shift the letter by key positions
      message[i] = ((message[i] - 'A') + key) % 26 + 'A';
    }
    i++;
  }

  printf("Encrypted message: %s", message);

  return 0;
}