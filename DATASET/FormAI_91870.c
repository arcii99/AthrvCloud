//FormAI DATASET v1.0 Category: Syntax parsing ; Style: excited
#include <stdio.h> 

int main() 
{ 
  printf("Wow! I am really excited to create a C Syntax parsing program!\n"); 
  printf("Let's get started with some code!\n\n"); 

  char input[100];
  printf("Enter a C Syntax expression: ");
  fgets(input, 100, stdin);

  printf("\nParsing the input...\n");
  int i = 0;
  int open_parentheses_count = 0;
  int close_parentheses_count = 0;

  while(input[i] != '\0') {
    if(input[i] == '(') {
      open_parentheses_count++;
    } else if(input[i] == ')') {
      close_parentheses_count++;
    }
    i++;
  }

  if(open_parentheses_count == close_parentheses_count) {
    printf("\nInput is well-parenthesized!\n");
  } else if(open_parentheses_count > close_parentheses_count) {
    printf("\nInput is not well-parenthesized!\n");
    printf("You need to close %d more parentheses.\n", open_parentheses_count - close_parentheses_count);
  } else {
    printf("\nInput is not well-parenthesized!\n");
    printf("You need to open %d more parentheses.\n", close_parentheses_count - open_parentheses_count);
  }

  return 0; 
}