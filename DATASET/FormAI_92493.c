//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
/* This program is a text processing tool that uses gratitude as a theme. It accepts user input, processes it and outputs a message of gratitude to the user. */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[1000], gratefulMessage[1000];
  int i, j;

  // Get user input
  printf("Enter a message: ");
  fgets(message, sizeof(message), stdin);

  // Remove trailing newline character from user input
  if (message[strlen(message) - 1] == '\n') {
    message[strlen(message) - 1] = '\0';
  }

  // Process user input
  strcpy(gratefulMessage, "I am grateful for ");
  for (i = 0, j = strlen(gratefulMessage); i < strlen(message); i++) {
    if (isalpha(message[i])) {
      gratefulMessage[j] = toupper(message[i]);
      j++;
    }
  }
  gratefulMessage[j] = '\0';

  // Display gratitude message to user
  printf("%s!\n", gratefulMessage);
  printf("Thank you for sharing your message. Have a blessed day!\n");

  return 0;
}