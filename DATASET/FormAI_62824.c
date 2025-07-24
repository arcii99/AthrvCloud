//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000

int main() {
  char input[MAX_INPUT_SIZE];
  
  printf("Enter your message: ");
  fgets(input, MAX_INPUT_SIZE, stdin);
  
  for(int i = 0; i < strlen(input); i++) {
    if(isalnum(input[i])) {
      if(isupper(input[i])) {
        putchar(tolower(input[i])); //converting uppercase letters to lowercase
      } else {
        putchar(input[i]);
      }
    } else {
      if(input[i] == ' ') {
        putchar(input[i]); //leaving space as it is
      } else {
        putchar('_'); //replacing all other non-alphanumeric characters with underscores
      }
    }
  }
  
  return 0;
}