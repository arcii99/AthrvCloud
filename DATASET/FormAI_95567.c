//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void error_handling(int err_code);

int main() {
  int num1, num2, result;
  
  printf("Enter two integers: ");
  if (scanf("%d %d", &num1, &num2) != 2) {
    error_handling(-1);
  }
  
  if (num2 == 0) {
    error_handling(-2);
  }
  
  result = num1 / num2;
  
  printf("%d / %d = %d\n", num1, num2, result);
  
  return 0;
}

void error_handling(int err_code) {
  switch(err_code) {
    case -1:
      printf("Error: Invalid input. Please enter two integers.\n");
      break;
    case -2:
      printf("Error: Division by zero.\n");
      break;
    default:
      printf("Unknown error.\n");
  }
  exit(err_code);
}