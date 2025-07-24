//FormAI DATASET v1.0 Category: Error handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, result;
  
  printf("Enter two numbers: ");
  if(scanf("%d %d", &num1, &num2) != 2) {
    fprintf(stderr, "Invalid input. Please enter two numbers separated by a space.\n");
    exit(EXIT_FAILURE);
  }
  
  if(num2 == 0) {
    fprintf(stderr, "Error: second number cannot be 0.\n");
    exit(EXIT_FAILURE);
  }
  
  result = num1 / num2;
  printf("Result: %d\n", result);
  
  return 0;
}