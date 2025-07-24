//FormAI DATASET v1.0 Category: Syntax parsing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void parse(char *input);

int main() {
  char input[] = "int x = 5;";
  parse(input);
  return 0;
}

void parse(char *input) {
  char *ptr = input;
  char *type = "";
  char *name = "";
  char *value = "";

  // Get the variable type
  while (isalpha(*ptr)) {
    type += *ptr;
    ptr++;
  }

  // Get the variable name
  while (*ptr == ' ') {
    ptr++; // skip whitespace
  }

  while (isalpha(*ptr)) {
    name += *ptr;
    ptr++;
  }

  // Get the variable value
  while (*ptr == ' ') {
    ptr++;
  }

  if (*ptr == '=') {
    ptr++; // skip the equals sign
    while (*ptr == ' ') {
      ptr++; // skip whitespace
    }
    while (isdigit(*ptr)) {
      value += *ptr;
      ptr++;
    }
  }

  printf("Variable Type: %s \n", type);
  printf("Variable Name: %s \n", name);
  if (value != "") {
    printf("Variable Value: %s \n", value);
  }
}