//FormAI DATASET v1.0 Category: Syntax parsing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter a C expression: ");
  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = 0; // remove newline character from input
  
  char* current = input;
  int num_open = 0;
  int num_close = 0;
  
  while (*current) { // loop through each character in input
    if (*current == '(') {
      num_open++;
    } else if (*current == ')') {
      num_close++;
      if (num_close > num_open) { // more closing parenthesis than opening, invalid expression
        printf("Invalid C expression!\n");
        return 0;
      }
    }
    current++;
  }
  
  if (num_open == num_close) { // valid expression
    printf("Valid C expression!\n");
  } else {
    printf("Invalid C expression!\n");
  }
  
  return 0;
}