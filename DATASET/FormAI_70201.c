//FormAI DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHHOLD 3

// The post-apocalyptic Spam Detection System
int main() {
  int numMessages = 0;
  char messages[10][100];
  int spamCount[10] = {0};
  
  while (numMessages < 10) {
    printf("Enter message %d (or type 'exit' to quit): ", numMessages + 1);
    fgets(messages[numMessages], 100, stdin);
    
    if (strcmp(messages[numMessages], "exit\n") == 0) {
      break; // Exit the loop if the user types 'exit'
    }
    
    for (int i = 0; i < numMessages; i++) {
      if (strcmp(messages[i], messages[numMessages]) == 0) {
        spamCount[i]++;
        if (spamCount[i] >= SPAM_THRESHHOLD) {
          printf("WARNING: Possible spam detected!\n");
        }
      }
    }

    numMessages++;
  }

  printf("Thank you for using the Post-Apocalyptic Spam Detection System.\n");

  return 0;
}