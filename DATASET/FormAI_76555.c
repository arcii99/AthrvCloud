//FormAI DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>

int main() {
  char message[] = "easiest way to process audio!";
  printf("Original message: %s\n", message);
  
  // reverse the characters in the message
  int length = strlen(message);
  for (int i = 0; i < length / 2; i++) {
    char temp = message[i];
    message[i] = message[length - 1 - i];
    message[length - 1 - i] = temp;
  }
  
  printf("Processed message: %s\n", message);
  
  return 0;
}