//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char string[]){
  int i, j = 0;
  char sanitizedString[100];

  for(i=0; i<strlen(string); i++){
    if(isalnum(string[i]))
      sanitizedString[j++] = tolower(string[i]);
  }
  sanitizedString[j] = '\0';

  strcpy(string, sanitizedString);
}

int main() {
  char input[100];

  printf("Enter input: ");
  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = '\0';

  sanitize(input);

  printf("Sanitized input: %s\n", input);

  return 0;
}