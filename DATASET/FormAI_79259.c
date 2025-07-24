//FormAI DATASET v1.0 Category: Syntax parsing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char expression[50]; // this will store our user input expression
  int i, length, errCount = 0; // errCount will be used to keep track of syntax errors
  
  printf("Enter an expression: "); // prompting user for input
  fgets(expression, 50, stdin); // getting user input via standard input
  
  // removing trailing newline character from user input
  length = strlen(expression);
  if (expression[length-1] == '\n') {
    expression[length-1] = '\0';
  }
  
  // checking if user input is valid syntax (i.e. has matching open and close parentheses)
  for (i = 0; i < length; i++) {
    if (expression[i] == '(') {
      errCount++; // add one to errCount for each open parentheses found
    } else if (expression[i] == ')') {
      errCount--; // subtract one from errCount for each close parentheses found
    }
  }
  
  // checking for errors
  if (errCount != 0) {
    printf("Syntax error!\n"); // if errCount is not zero, then there are unmatched parentheses
    return 1;
  } else {
    printf("Syntax is correct.\n"); // if errCount is zero, then syntax is correct
    return 0;
  }
}