//FormAI DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  printf("Enter thy message, sire: ");
  fgets(message, 1000, stdin);
  printf("------------------------\n\n");
  printf("Thy message, sire: \n\n%s\n", message);

  // Process the message
  int messageLength = strlen(message);
  for(int i = 0; i < messageLength; i++) {
    if(message[i] >= 'a' && message[i] <= 'z') {
      message[i] = message[i] - 'a' + 'A'; // Convert to uppercase
    }

    if(message[i] >= 'A' && message[i] <= 'Z') {
      message[i] = message[i] + 3; // Shift 3 positions forward
      if(message[i] > 'Z') {
        message[i] = message[i] - 'Z' + 'A' - 1; // Wrap around
      }
    }

    if(message[i] == '\n') {
      printf("\n"); // Print a new line instead of the newline character
    } else {
      putchar(message[i]); // Print the processed character
    }
  }

  printf("\n\nFare thee well, sire!\n");
  return 0;
}