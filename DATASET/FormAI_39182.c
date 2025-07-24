//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {

  char message[100];   // the message to check
  int counter=0;       // number of occurrences of the words "spam" and "sale"
  int i, j;            // loop counters

  // get the message from user input
  printf("Enter your message: ");
  fgets(message, sizeof(message), stdin);

  // remove the newline character at the end
  message[strlen(message) - 1] = '\0';

  // check for the words "spam" and "sale"
  for (i = 0; i < strlen(message); i++) {
    if (message[i] == 's' || message[i] == 'S') {
      if (message[i + 1] == 'p' || message[i + 1] == 'P') {
        if (message[i + 2] == 'a' || message[i + 2] == 'A') {
          if (message[i + 3] == 'm' || message[i + 3] == 'M') {
            counter++;
          }
        }
      }
      if (message[i + 1] == 'a' || message[i + 1] == 'A') {
        if (message[i + 2] == 'l' || message[i + 2] == 'L') {
          if (message[i + 3] == 'e' || message[i + 3] == 'E') {
            counter++;
          }
        }
      }
    }
  }

  // output the result
  printf("Occurrences of the words 'spam' and 'sale': %d\n", counter);

  // classify the message as spam or not
  if (counter >= 2) {
    printf("WARNING: This message is likely spam.\n");
  } else {
    printf("This message is not spam.\n");
  }

  return 0;
}