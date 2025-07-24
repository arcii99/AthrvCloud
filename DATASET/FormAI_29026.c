//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main() {
  char input[MAX_LEN+1];
  printf("Enter your input: ");
  fgets(input, MAX_LEN, stdin);
  input[strcspn(input, "\n")] = '\0'; // remove trailing newline
  
  // Remove non-alpha characters
  char sanitized[MAX_LEN+1];
  int j = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (isalpha(input[i])) {
      sanitized[j] = tolower(input[i]); // convert to lowercase
      j++;
    }
  }
  sanitized[j] = '\0'; // terminate sanitized string
  
  printf("Sanitized input: %s\n", sanitized);
  return 0;
}