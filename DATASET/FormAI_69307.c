//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  int i, spamCount = 0;

  printf("Enter message: ");
  fgets(message, 1000, stdin);

  // Check for spam keywords
  char *spamKeywords[] = {"buy", "discount", "sale", "free", "money back guarantee"};
  char *word = strtok(message, " ");
  while (word != NULL) {
    for (i = 0; i < 5; i++) {
      if (strstr(word, spamKeywords[i]) != NULL) {
        spamCount++;
        break;
      }
    }
    word = strtok(NULL, " ");
  }

  // Check message length
  int messageLength = strlen(message) - 1;  // Exclude newline character
  if (messageLength > 100) {
    spamCount++;
  }

  // Check message frequency
  static int messageCounter = 0;
  messageCounter++;
  if (messageCounter > 10) {
    spamCount++;
    messageCounter = 0;
  }

  if (spamCount > 1) {
    printf("Message is spam.\n");
  } else {
    printf("Message is not spam.\n");
  }

  return 0;
}