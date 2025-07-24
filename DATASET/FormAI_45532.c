//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
  char message[100] = "I like to eat bananas!";
  char newWord[10] = "ice cream";

  printf("Original message: %s\n", message);

  // Replace bananas with ice cream
  strncpy(message + 7, newWord, 8);

  printf("New message: %s\n", message);

  // Reverse the message
  int length = strlen(message);
  int halfLength = length / 2;

  for (int i = 0; i < halfLength; i++) {
    char temp = message[i];
    message[i] = message[length - 1 - i];
    message[length - 1 - i] = temp;
  }

  printf("Reversed message: %s\n", message);

  // Replace spaces with exclamation points
  for (int i = 0; i < length; i++) {
    if (message[i] == ' ') {
      message[i] = '!';
    }
  }

  printf("Crazy message: %s\n", message);

  return 0;
}