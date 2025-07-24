//FormAI DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100
#define SPAM_THRESHOLD 3

int main() {
  char message[MAX_MESSAGE_LENGTH];
  int count = 0;
  
  printf("Enter a message:\n");
  fgets(message, MAX_MESSAGE_LENGTH, stdin);
  
  // Check if message contains spam words
  if (strstr(message, "buy") || strstr(message, "cheap")) {
    count++;
  }
  
  if (strstr(message, "earn money fast") || strstr(message, "work from home")) {
    count++;
  }
  
  if (strstr(message, "get rich quick") || strstr(message, "make money fast")) {
    count++;
  }
  
  // Check if message exceeds spam threshold
  if (count >= SPAM_THRESHOLD) {
    printf("WARNING: This message appears to be spam.\n");
  } else {
    printf("Message saved.\n");
  }
  
  return 0;
}