//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  int spam_count = 0;
  int message_length;
  int i;

  printf("Welcome to the Spam Detection System!\n");
  printf("Enter a message: ");
  scanf("%s", message);

  message_length = strlen(message);

  for (i = 0; i < message_length; i++) {
    if (message[i] == 'f') {
      if (i + 1 < message_length && message[i+1] == 'r') {
        if (i + 2 < message_length && message[i+2] == 'e') {
          if (i + 3 < message_length && message[i+3] == 'e') {
            if (i + 4 < message_length && message[i+4] == ' ') {
              spam_count++;
            }
          }
        }
      }
    }
  }

  if (spam_count >= 2) {
    printf("Spam detected! This message will not be sent.\n");
  } else {
    printf("No spam detected. This message can be sent.\n");
  }

  return 0;
}