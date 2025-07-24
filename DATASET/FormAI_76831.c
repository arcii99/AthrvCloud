//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  // define variables
  char input[100];
  int i, j, len;
  char temp;
  
  // prompt user for input
  printf("Enter a string to sanitize: ");
  fgets(input, sizeof(input), stdin);
  
  // remove newline character from input
  len = strlen(input);
  if (input[len-1] == '\n') {
    input[len-1] = '\0';
    len--;
  }
  
  // sanitize input by converting to lowercase and removing non-alphabetic characters
  for (i = 0; i < len; i++) {
    input[i] = tolower(input[i]);
    if (!isalpha(input[i])) {
      for (j = i; j < len - 1; j++) {
        input[j] = input[j+1];
      }
      input[len-1] = '\0';
      len--;
      i--;
    }
  }
  
  // print sanitized input
  printf("Sanitized input: %s\n", input);
  
  return 0;
}