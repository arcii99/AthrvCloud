//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

int main() {
  int num1, num2, result;

  printf("Please enter the first number: ");
  scanf("%d", &num1);

  printf("Please enter the second number: ");
  scanf("%d", &num2);

  result = num1 + num2;
  printf("The sum of %d and %d is %d.\n", num1, num2, result);

  result = num1 - num2;
  printf("The difference between %d and %d is %d.\n", num1, num2, result);

  result = num1 * num2;
  printf("The product of %d and %d is %d.\n", num1, num2, result);

  if (num2 != 0) {
    result = num1 / num2;
    printf("The quotient of %d divided by %d is %d.\n", num1, num2, result);

    result = num1 % num2;
    printf("The remainder of %d divided by %d is %d.\n", num1, num2, result);
  }
  else {
    printf("Cannot divide by 0.\n");
  }

  result = num1++;
  printf("The value of num1 after incrementing is %d.\n", result);

  result = num2--;
  printf("The value of num2 after decrementing is %d.\n", result);

  return 0;
}