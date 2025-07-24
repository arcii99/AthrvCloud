//FormAI DATASET v1.0 Category: Syntax parsing ; Style: secure
// Example C Syntax Parsing Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void secure_parse(char *input) {
  char buffer[20];
  int i, j, len;
  len = strlen(input);
  // Check for buffer overflow
  if(len > 20) {
    printf("Error: Input length exceeds buffer limit!\n");
    exit(1);
  }
  // Parse input string
  for(i=0, j=0; input[i]; i++) {
    if(input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}') {
      // Add space before and after parentheses and braces
      buffer[j++] = ' ';
      buffer[j++] = input[i];
      buffer[j++] = ' ';
    }
    else {
      buffer[j++] = input[i];
    }
  }
  buffer[j] = '\0';
  // Print parsed string
  printf("Parsed string: %s\n", buffer);
}

int main() {
  char input[100];
  printf("Enter string to parse: ");
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0'; // remove trailing newline character
  secure_parse(input);
  return 0;
}