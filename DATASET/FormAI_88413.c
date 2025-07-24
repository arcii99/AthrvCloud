//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main(void) {
  char input[MAX_INPUT_LENGTH];
  char output[MAX_INPUT_LENGTH];
  int i, j=0;
  
  printf("Enter your input: ");
  fgets(input, sizeof(input), stdin);
  
  // Remove any newline characters included in the input
  for(i = 0; input[i] != '\n'; i++);
  input[i] = '\0';

  // Check for and remove any non-letter/digit/space characters
  for(i = 0; input[i] != '\0'; i++) {
    if(isalnum(input[i]) || isspace(input[i])) {
      output[j++] = input[i];
    }
  }
  output[j] = '\0';

  // Convert all alphabetic characters in the output to uppercase
  // Optional: could also convert to lowercase
  for(i = 0; output[i] != '\0'; i++) {
    if(isalpha(output[i])) {
      output[i] = toupper(output[i]);
    }
  }
  
  printf("Your sanitized input is: %s", output);
  
  return 0;
}