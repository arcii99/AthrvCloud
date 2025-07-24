//FormAI DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  int spam_count = 0;
  
  printf("Welcome to the Spam Detection System!\n\n");
  printf("Please enter a message:\n");
  
  fgets(message, 100, stdin);
  
  // check for spam keywords
  if (strstr(message, "free") != NULL || strstr(message, "click here") != NULL) {
    spam_count++;
  }
  
  // check for excessive use of exclamation points
  int exclamation_count = 0;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == '!') {
      exclamation_count++;
    }
  }
  
  if (exclamation_count >= 3) {
    spam_count++;
  }
  
  // check if message is all caps
  int all_caps = 1;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      all_caps = 0;
      break;
    }
  }
  
  if (all_caps == 1) {
    spam_count++;
  }
  
  if (spam_count == 0) {
    printf("This message appears to be safe!\n");
    return 0;
  } else {
    printf("Warning: This message may be spam!\n");
    return 1;
  }
}