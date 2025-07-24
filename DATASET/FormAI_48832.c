//FormAI DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
  
  char message[100];
  int num_spams = 0;
  int num_warnings = 0;
  
  printf("Welcome to the Medieval Spam Detection System!\n");
  printf("Please enter a message to check for spam:\n");
  
  fgets(message, 100, stdin);
  
  // check for banned words
  if (strstr(message, "magic potion") != NULL || strstr(message, "get rich quick") != NULL) {
    num_spams++;
  }
  
  // check for excessive punctuation
  int num_punct = 0;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == '!' || message[i] == '?' || message[i] == '.') {
      num_punct++;
    }
  }
  if (num_punct > 3) {
    num_warnings++;
  }
  
  // check for all caps
  int all_caps = 1;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      all_caps = 0;
      break;
    }
  }
  if (all_caps == 1) {
    num_warnings++;
  }
  
  // output results
  printf("Results:\n");
  if (num_spams > 0) {
    printf("This message contains %d instances of spam.\n", num_spams);
    printf("This message will not be sent.\n");
  } else {
    printf("This message does not contain any spam.\n");
    if (num_warnings > 0) {
      printf("However, this message contains %d warning(s).\n", num_warnings);
    }
    printf("This message is safe to send.\n");
  }
  
  return 0;
}