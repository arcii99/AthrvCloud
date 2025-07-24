//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>

int main() {
  char input[100];
  printf("Enter a mathematical expression: ");
  scanf("%s", input);
  
  int i, j;
  char operator = '\0';
  int number;
  for (i = 0; input[i] != '\0'; i++) {
    if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
      operator = input[i];
      j = i + 1;
      break;
    }
  }
  
  if (operator == '\0') {
    printf("Error: no operator found in input");
    return 1;
  }
  
  number = input[0] - '0';
  for (i = j; input[i] != '\0'; i++) {
    if (input[i] < '0' || input[i] > '9') {
      printf("Error: unexpected character '%c'", input[i]);
      return 1;
    }
    int digit = input[i] - '0';
    if (operator == '+') {
      number += digit;
    } else if (operator == '-') {
      number -= digit;
    } else if (operator == '*') {
      number *= digit;
    } else {
      if (digit == 0) {
        printf("Error: division by zero");
      }
      number /= digit;
    }
  }
  
  printf("Result: %d", number);
  return 0;
}