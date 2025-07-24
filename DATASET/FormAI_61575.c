//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[256];
  printf("Enter a string:\n");
  fgets(input, sizeof(input), stdin);

  for(int i = 0; input[i] != '\0'; i++){
    if(input[i] == '\n'){
      input[i] == '\0';
      break;
    }
    if(!(isalnum(input[i]) || isspace(input[i]))){
      input[i] = '-';
    }
    if(isspace(input[i])){
      input[i] = '_';
    }
  }

  printf("Sanitized input: %s\n", input);
  return 0;
}