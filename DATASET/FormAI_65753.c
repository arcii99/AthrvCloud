//FormAI DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 8192

int main() {
  char buffer[MAX_BUFFER_SIZE]; // A buffer to store the input source code
  int line_number = 1; // A counter to track the current line number
  int syntax_error = 0; // A flag to track whether any syntax errors have occurred

  // Prompt the user to enter the source code
  printf("Enter C source code:\n");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Tokenize the input source code based on whitespace and newlines
  char* token = strtok(buffer, " \t\n\r");

  // Loop through all tokens in the input source code
  while (token != NULL) {
    // Check if the token is a keyword, identifier, or integer
    if (strcmp(token, "int") == 0 ||
        strcmp(token, "char") == 0 ||
        strcmp(token, "float") == 0 ||
        strcmp(token, "double") ==0) {
      printf("Keyword <%s> found on line %d\n", token, line_number);
    } else if (isalpha(token[0])) {
      printf("Identifier <%s> found on line %d\n", token, line_number);
    } else if (isdigit(token[0])) {
      printf("Integer <%s> found on line %d\n", token, line_number);
    } else {
      printf("Syntax error: <%s> found on line %d\n", token, line_number);
      syntax_error = 1;
    }

    // Move to the next token and increment the line number if a newline is found
    token = strtok(NULL, " \t\n\r");
    if (token == NULL || token[0] == '\n') {
      line_number++;
    }
  }

  // If any syntax errors occurred, notify the user and exit the program with a non-zero status
  if (syntax_error) {
    printf("Syntax errors detected. Exiting program with status code 1\n");
    exit(1);
  }

  // If no syntax errors occurred, notify the user and exit the program with a zero status
  printf("Syntax check passed. Exiting program with status code 0\n");
  exit(0);
}