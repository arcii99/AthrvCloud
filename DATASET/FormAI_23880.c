//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num, choice;
  float result;
  printf("Enter a number: ");
  scanf("%d", &num);
  printf("Choose an operation:\n");
  printf("1. Square root\n");
  printf("2. Cube root\n");
  printf("3. Factorial\n");
  printf("4. Absolute value\n");
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      result = sqrt(num);
      printf("Square root of %d is %f", num, result);
      break;
    case 2:
      result = cbrt(num);
      printf("Cube root of %d is %f", num, result);
      break;
    case 3:
      result = 1;
      for(int i = 1; i <= num; i++) {
        result *= i;
      }
      printf("Factorial of %d is %f", num, result);
      break;
    case 4:
      result = abs(num);
      printf("Absolute value of %d is %f", num, result);
      break;
    default:
      printf("Invalid choice");
      break;
  }
  return 0;
}