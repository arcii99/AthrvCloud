//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complex
#include <stdio.h>

// define a struct to hold a variable declaration
typedef struct {
  char* type;
  char* name;
} variable;

int main() {
  printf("Enter a variable declaration in C syntax: ");

  // read in the user input for a variable declaration
  char declaration[100];
  scanf("%s", declaration);

  // initialize variables to parse the declaration
  char* c = declaration;
  variable var;
  var.type = "";
  var.name = "";

  // loop through the characters in the declaration and parse the type and name
  while (*c != '\0') {
    if (*c == ' ') {  // space indicates end of type and beginning of name
      var.name = c + 1;
    } else if (*c == '*' && var.type == "") {  // pointer to a type
      var.type = "pointer to";
    } else if (*c == '[' && var.type == "") {  // array of a type
      var.type = "array of";
    } else if (*c == ']') {  // end of array declaration
      var.type = "";
    } else if (var.type == "") {  // add character to type string
      var.type += *c;
    }
    c++;
  }

  // output the parsed variable declaration
  printf("Type: %s\nName: %s\n", var.type, var.name);

  return 0;
}