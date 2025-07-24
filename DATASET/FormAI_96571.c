//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter your name: ");
  fgets(input, 100, stdin);
  int len = strlen(input);
  
  // check for newline character
  if (input[len-1] == '\n') {
    input[len-1] = '\0'; // replace with null character
  }
  
  // check for special characters
  for (int i = 0; i < len; i++) {
    if (!(input[i] >= 'a' && input[i] <= 'z') && 
        !(input[i] >= 'A' && input[i] <= 'Z') && 
        !(input[i] >= '0' && input[i] <= '9') &&
        !(input[i] == ' ')) {
      printf("Invalid input!\n");
      return 1;
    }
  }
  
  printf("Hello, %s!\n", input);
  return 0;
}