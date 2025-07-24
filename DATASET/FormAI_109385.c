//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int num1, num2, result;
  
  printf("Enter two numbers to divide: ");
  scanf("%d%d", &num1, &num2);
  
  if (num2 == 0) {
    printf("Cannot divide by zero! Exiting program.");
    exit(0);
  }
  
  result = num1 / num2;
  
  printf("Result of division: %d", result);
  
  return 0;
}