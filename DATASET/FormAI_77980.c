//FormAI DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 1000

int main() {
  char message[MAX_CHARS];
  char reverseMessage[MAX_CHARS];
  char copyMessage[MAX_CHARS];

  // Prompt user to enter a message
  printf("Enter a message: ");
  fgets(message, MAX_CHARS, stdin);

  // Remove the newline character from the input
  message[strcspn(message, "\n")] = 0;

  // Get the length of the message
  int length = strlen(message);

  // Print the original message
  printf("Original Message: %s\n", message);

  // Copy the original message to the copyMessage array
  strcpy(copyMessage, message);

  // Reverse the message and store it in reverseMessage
  int i, j;
  for (i = length - 1, j = 0; i >= 0; i--, j++) {
    reverseMessage[j] = message[i];
  }
  reverseMessage[length] = '\0';

  // Print the reversed message
  printf("Reversed Message: %s\n", reverseMessage);

  // Concatenate the copy of the original message with the reversed message
  strcat(copyMessage, reverseMessage);

  // Print the concatenated message
  printf("Concatenated Message: %s\n", copyMessage);

  return 0;
}