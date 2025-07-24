//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000];
  int spam_count = 0;
  
  while (1) {
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    if (strcmp(message, "exit\n") == 0) {
      break;
    }
    
    // Check for spam keywords
    if (strstr(message, "buy") || strstr(message, "cheap") || strstr(message, "discount")) {
      printf("WARNING: This message might be spam.\n");
      spam_count++;
    } else {
      printf("This message is not spam.\n");
    }
  }
  
  printf("You received %d spam message(s).\n", spam_count);
  
  return 0;
}