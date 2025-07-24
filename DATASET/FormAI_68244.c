//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

int main() {
  char message[MAX_MESSAGE_LENGTH];
  printf("Enter a message: ");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);
  message[strcspn(message, "\n")] = 0; // remove trailing newline character
  printf("Message: %s\n", message);
  return 0;
}