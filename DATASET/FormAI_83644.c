//FormAI DATASET v1.0 Category: Syntax parsing ; Style: futuristic
/* Welcome to the futuristic syntax parsing example program! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  
  // Gather input code from user
  printf("Enter your code here:\n");
  char code[1000];
  fgets(code, 1000, stdin);
  
  // Tokenize input code into individual syntax elements
  char* token;
  const char delimiter[] = " ;(){}[]+-*/%=<>&|!";
  token = strtok(code, delimiter);
  
  while (token != NULL) {
    // Check for specific syntax elements and perform respective action
    if (strcmp(token, "if") == 0) {
      printf("Conditional statement detected\n");
    } else if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0) {
      printf("Data type declaration detected\n");
    } else if (strcmp(token, "for") == 0 || strcmp(token, "while") == 0) {
      printf("Loop detected\n");
    } else if (strcmp(token, "=") == 0) {
      printf("Assignment detected\n");
    } else if (strcmp(token, "==") == 0 || strcmp(token, "!=") == 0) {
      printf("Comparison operator detected\n");
    } else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
               strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
      printf("Mathematical operator detected\n");
    } else if (strcmp(token, "true") == 0 || strcmp(token, "false") == 0) {
      printf("Boolean constant detected\n");
    } else {
      printf("Syntax element detected: %s\n", token);
    }
    token = strtok(NULL, delimiter);
  }
  
  // End of program
  printf("\nSyntax parsing complete\n");
  return 0;
}