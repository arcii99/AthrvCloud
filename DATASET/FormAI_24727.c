//FormAI DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  int i, spamCount = 0;

  printf("Enter your message: \n");
  fgets(message, 100, stdin); // get input from user

  // check for specific spam keywords
  if (strstr(message, "CLICK HERE") || strstr(message, "MAKE MONEY FAST") || strstr(message, "FREE MONEY")) {
    spamCount++;
  }

  // check for excessive exclamation marks
  for (i = 0; i < strlen(message) - 1; i++) {
    if (message[i] == '!' && message[i+1] == '!') {
      spamCount++;
    }
  }

  // check for repeated characters in a row
  for (i = 0; i < strlen(message) - 2; i++) {
    if (message[i] == message[i+1] && message[i+1] == message[i+2]) {
      spamCount++;
    }
  }

  // output results based on spam count
  if (spamCount == 0) {
    printf("Congratulations! Your message is not spam.\n");
  } else if (spamCount == 1) {
    printf("Your message has been flagged as possible spam.\nPlease verify your message content and try again.\n");
  } else {
    printf("Your message has been flagged as spam.\nPlease contact customer support for further assistance.\n");
  }

  return 0;
}