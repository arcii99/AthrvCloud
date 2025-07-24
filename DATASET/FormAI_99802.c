//FormAI DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the C Syntax Parser!\n\n");
  
  // Get input string from user
  printf("Please enter a line of C code: ");
  char input[1000];
  fgets(input, 1000, stdin);

  // Loop through the input string and parse each token
  char* token = strtok(input, " \t\n");
  while (token != NULL) {
    // Check if token is a keyword
    if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 ||
        strcmp(token, "double") == 0 || strcmp(token, "char") == 0) {
      printf("%s is a keyword.\n", token);
    }
    // Check if token is an identifier
    else if (isalpha(token[0])) {
      printf("%s is an identifier.\n", token);
    }
    // Check if token is a number
    else if (isdigit(token[0])) {
      int i = 0;
      while (isdigit(token[i])) {
        i++;
      }
      if (token[i] == '.') {
        i++;
        while (isdigit(token[i])) {
          i++;
        }
        printf("%s is a floating-point constant.\n", token);
      } else {
        printf("%s is an integer constant.\n", token);
      }
    }
    // Check if token is an operator
    else if (strchr("+-*/%=", token[0]) != NULL) {
      printf("%s is an operator.\n", token);
    }
    // Check if token is a delimiter
    else if (strchr("(),;{}", token[0]) != NULL) {
      printf("%s is a delimiter.\n", token);
    }
    // Token not recognized
    else {
      printf("Error: Unrecognized token %s.\n", token);
    }
    
    // Move on to the next token
    token = strtok(NULL, " \t\n");
  }
  
  // Goodbye message
  printf("\nThanks for using the C Syntax Parser!\n");
  
  return 0;
}