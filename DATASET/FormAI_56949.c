//FormAI DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* decentralized function to process a message */
void process_message(char *message) {
  int len = strlen(message);
  
  /* convert message to uppercase */
  for (int i = 0; i < len; i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      message[i] = message[i] - ('a' - 'A');
    }
  }
  
  /* remove any punctuations */
  for (int i = 0; i < len; i++) {
    if (message[i] == '.' || message[i] == ',' || message[i] == '!' || message[i] == '?') {
      for (int j = i; j < len; j++) {
        message[j] = message[j+1];
      }
      len--;
    }
  }
  
  /* remove any extra spaces */
  for (int i = 0; i < len; i++) {
    if (message[i] == ' ' && message[i+1] == ' ') {
      for (int j = i+1; j < len; j++) {
        message[j] = message[j+1];
      }
      len--;
      i--;
    }
  }
  
  /* print the final message */
  printf("Processed message: %s\n", message);
}

int main() {
  char message[100];
  
  /* get input from user */
  printf("Enter your message (max 100 characters):\n");
  fgets(message, sizeof(message), stdin);
  
  /* remove newline character from input */
  if ((strlen(message) > 0) && (message[strlen (message) - 1] == '\n')) {
        message[strlen (message) - 1] = '\0';
  }
  
  /* process the message */
  process_message(message);
  
  return 0;
}