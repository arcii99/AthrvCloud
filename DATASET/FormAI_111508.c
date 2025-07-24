//FormAI DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char userInput[100];
  printf("Enter your code: ");
  fgets(userInput, 100, stdin);

  // Let's check if the code starts with the keyword "int"
  if (strncmp(userInput, "int", 3) == 0) {
    char* variableName = strtok(userInput + 4, "() ");
    int variableValue = atoi(strtok(NULL, "() "));
    printf("Variable name: %s\n", variableName);
    printf("Variable value: %d\n", variableValue);
  }
  else {
    printf("Invalid code! Only integer variables are supported.");
  }

  return 0;
}