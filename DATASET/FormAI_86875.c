//FormAI DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {

  char userInput[100];
  printf("Enter a C syntax statement: ");
  scanf("%s", userInput);

  int i = 0;
  while(userInput[i] != '\0') {
    if(userInput[i] == '{') {
      printf("Open curly bracket found\n");
    }
    else if(userInput[i] == '}') {
      printf("Closing curly bracket found\n");
    }
    else if(userInput[i] == ';') {
      printf("Semicolon found\n");
    }
    else if(userInput[i] == '(') {
      printf("Open parenthesis found\n");
    }
    else if(userInput[i] == ')') {
      printf("Closing parenthesis found\n");
    }
    else if(userInput[i] == ',') {
      printf("Comma found\n");
    }

    i++;
  }

  return 0;
}