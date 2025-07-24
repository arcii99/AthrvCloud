//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[1000];
  printf("Please enter some text:\n");
  fgets(input, sizeof(input), stdin); // get user input

  // remove new line character at the end of input
  if(input[strlen(input) - 1] == '\n')
    input[strlen(input) - 1] = '\0';

  // sanitize user input to only allow letters and spaces
  for(int i = 0; i < strlen(input); i++) {
    if(!isalpha(input[i]) && !isspace(input[i])) {
      input[i] = ' ';
    }
  }

  printf("Sanitized text:\n%s\n", input);

  return 0;
}