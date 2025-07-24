//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>

int main() {
  int a, b, c;

  printf("Enter the first number: ");
  scanf("%d", &a);

  printf("Enter the second number: ");
  scanf("%d", &b);

  printf("Enter the third number: ");
  scanf("%d", &c);

  int sum = a + b + c;

  printf("The sum of the three numbers is %d.\n", sum);

  int product = a * b * c;

  printf("The product of the three numbers is %d.\n", product);

  float average = (float)sum / 3;

  printf("The average of the three numbers is %.2f.\n", average);

  printf("The first number raised to the power of the second number is %d.\n", power(a, b));

  printf("The second number raised to the power of the third number is %d.\n", power(b, c));

  printf("The third number raised to the power of the first number is %d.\n", power(c, a));

  return 0;
}

int power(int base, int exponent) {
  int result = 1;

  for (int i = 0; i < exponent; i++) {
    result *= base;
  }

  return result;
}