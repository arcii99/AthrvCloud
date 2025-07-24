//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  int i, j, spamCount = 0;
  
  printf("Enter your message: ");
  fgets(message, sizeof(message), stdin);
  
  char spamWords[10][20] = {"offer", "free", "money", "win", "prize", "limited", "call", "click", "unsubscribe", "act now"};
  
  char *token = strtok(message, " ,\n");
  while (token != NULL) {
    for (i = 0; i < 10; i++) {
      if (strstr(token, spamWords[i]) != NULL) {
        spamCount++;
      }
    }
    token = strtok(NULL, " ,\n");
  }
  
  if (spamCount > 0) {
    printf("Warning! This message could be spam.\n");
  } else {
    printf("This message appears to be legitimate.\n");
  }
  
  return 0;
}