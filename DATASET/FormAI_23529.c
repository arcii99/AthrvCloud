//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char input[50];
  printf("Enter a C syntax statement:\n");
  fgets(input, sizeof(input), stdin); // get user input

  int length = strlen(input);
  if(input[length-1] == '\n') {
    input[length-1] = '\0'; // get rid of newline character
    length--;
  }

  int i, j, space_check = 0, bracket_check = 0;
  for(i = 0; i < length; i++) {
    if(input[i] == ' ') {
      space_check++; // check for spaces
    }
    else if(input[i] == '{' || input[i] == '}') {
      bracket_check++; // check for brackets
    }
  }

  if(space_check > 0 && bracket_check > 0) {
    printf("This is a valid C syntax statement.\n");
  }
  else {
    printf("This is not a valid C syntax statement.\n");
  }

  return 0;
}