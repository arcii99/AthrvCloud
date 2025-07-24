//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  int isSpam = 0;

  printf("Enter message: ");
  fgets(message, 100, stdin);

  // Check for spam words
  if (strstr(message, "money") != NULL ||
      strstr(message, "$$$") != NULL ||
      strstr(message, "sale") != NULL ||
      strstr(message, "offer") != NULL) {
    isSpam = 1;
  }

  // Check for excessive uppercase letters
  int uppercaseCount = 0;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] >= 'A' && message[i] <= 'Z') {
      uppercaseCount++;
    }
  }
  if (uppercaseCount > strlen(message) / 4) {
    isSpam = 1;
  }

  // Check for multiple exclamation marks
  int exclamationCount = 0;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == '!') {
      exclamationCount++;
    }
  }
  if (exclamationCount > 2) {
    isSpam = 1;
  }

  if (isSpam) {
    printf("This message is spam\n");
  } else {
    printf("This message is not spam\n");
  }

  return 0;
}