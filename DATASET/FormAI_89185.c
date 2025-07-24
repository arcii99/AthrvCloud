//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

int main() {
  int num1, num2, num3, result;

  printf("Enter three integers: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  // Add three numbers
  result = num1 + num2 + num3;
  printf("Sum of three numbers: %d\n", result);

  // Subtract num2 from num1
  result = num1 - num2;
  printf("Num1 - Num2: %d\n", result);

  // Multiply num1 and num3
  result = num1 * num3;
  printf("Num1 * Num3: %d\n", result);

  // Divide num1 by num2
  result = num1 / num2;
  printf("Num1 / Num2: %d\n", result);

  // Modulus of num3 and num2
  result = num3 % num2;
  printf("Num3 %% Num2: %d\n", result);

  return 0;
}