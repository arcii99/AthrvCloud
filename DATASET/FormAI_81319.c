//FormAI DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>

int main() {
  printf("Welcome to my unique C syntax parsing example program!\n");
  printf("Today we'll be exploring how to parse a C function definition.\n");
  printf("First, let's look at an example function definition:\n\n");

  char func_def[] = "int add(int x, int y) { return x + y; }";
  printf("%s\n\n", func_def);

  printf("Our goal is to extract the function name, return type, parameter types, and body.\n");

  // First we'll extract the return type
  char return_type[10];
  sscanf(func_def, "%s", return_type);
  printf("Return type: %s\n", return_type);

  // Now we'll extract the function name
  char function_name[10];
  sscanf(func_def, "%*s %s", function_name);
  printf("Function name: %s\n", function_name);

  // Next we'll extract the parameter types
  char parameter_types[20];
  sscanf(func_def, "%*s %*s (%[^)])", parameter_types);
  printf("Parameter types: %s\n", parameter_types);

  // Finally we'll extract the body
  char body[50];
  sscanf(func_def, "%*s %*s (%*[^)]) {%[^}]", body);
  printf("Body: %s\n", body);

  printf("\nThere you have it! We've successfully parsed a C function definition.\n");

  return 0;
}