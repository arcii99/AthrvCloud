//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main(void) {
  char message[100];
  int spam_count = 0;

  printf("Enter messages (type 'exit' to stop):\n");

  while (1) {
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; /* remove newline character */

    if (strcmp(message, "exit") == 0) {
      break;
    }

    /* Check for spam words */
    if (strstr(message, "buy now") != NULL) {
      printf("Spam detected: '%s'\n", message);
      spam_count++;
    } else if (strstr(message, "make money fast") != NULL) {
      printf("Spam detected: '%s'\n", message);
      spam_count++;
    } else if (strstr(message, "click here") != NULL) {
      printf("Spam detected: '%s'\n", message);
      spam_count++;
    }
  }

  printf("\nTotal spam messages detected: %d\n", spam_count);

  return 0;
}