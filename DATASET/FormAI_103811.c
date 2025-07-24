//FormAI DATASET v1.0 Category: Syntax parsing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global constants
const int MAX_LEN = 128;
const char* KEYWORDS[] = {"int", "char", "float", "double", "return", "if", "else", "while", "for"};
const int NUM_KEYWORDS = 9;

// Function prototypes
int is_keyword(char* token);
int is_operator(char token);
int is_identifier(char* token);
int is_literal(char* token);

int main() {
  char input[MAX_LEN];
  printf("Enter a C statement:\n");
  fgets(input, MAX_LEN, stdin);

  char* token = strtok(input, " ");
  while (token != NULL) {
    if (is_keyword(token)) {
      printf("%s is a keyword\n", token);
    } else if (is_operator(token[0])) {
      printf("%s is an operator\n", token);
    } else if (is_identifier(token)) {
      printf("%s is an identifier\n", token);
    } else if (is_literal(token)) {
      printf("%s is a literal\n", token);
    } else {
      printf("%s is not recognized\n", token);
    }

    token = strtok(NULL, " ");
  }

  return 0;
}

// Function to check if a token is a keyword
int is_keyword(char* token) {
  for (int i = 0; i < NUM_KEYWORDS; i++) {
    if (strcmp(token, KEYWORDS[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to check if a token is an operator
int is_operator(char token) {
  return (token == '+' || token == '-' || token == '*' || token == '/' || token == '=' || token == '>' || token == '<' || token == '|' || token == '&' || token == '!');
}

// Function to check if a token is a valid identifier
int is_identifier(char* token) {
  if (!isalpha(token[0])) {
    return 0;
  }
  for (int i = 1; i < strlen(token); i++) {
    if (!isalnum(token[i])) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a token is a valid literal
int is_literal(char* token) {
  if (isdigit(token[0])) {
    return 1;
  }
  return 0;
}