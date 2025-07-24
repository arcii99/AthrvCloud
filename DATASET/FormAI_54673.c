//FormAI DATASET v1.0 Category: Arithmetic ; Style: automated
#include <stdio.h>

int main() {
  int num1, num2, num3;
  printf("Enter three integers: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  int sum = num1 + num2 + num3;
  printf("\nThe sum of the three integers is: %d\n", sum);

  int product = num1 * num2 * num3;
  printf("The product of the three integers is: %d\n", product);

  int average = sum/3;
  printf("The average of the three integers is: %d\n", average);

  printf("The absolute values of the three integers are: %d, %d, %d\n", abs(num1), abs(num2), abs(num3));

  int max = num1;
  if (num2 > max) {
    max = num2;
  }
  if (num3 > max) {
    max = num3;
  }
  printf("The largest of the three integers is: %d\n", max);

  int min = num1;
  if (num2 < min) {
    min = num2;
  }
  if (num3 < min) {
    min = num3;
  }
  printf("The smallest of the three integers is: %d\n", min);

  printf("The square root of the sum of the squares of the three integers is: %.2f\n", sqrt(pow(num1, 2) + pow(num2, 2) + pow(num3, 2)));

  printf("The bitwise AND of the three integers is: %d\n", num1 & num2 & num3);

  printf("The bitwise OR of the three integers is: %d\n", num1 | num2 | num3);

  if (num1 % 2 == 0) {
    printf("%d is even\n", num1);
  } else {
    printf("%d is odd\n", num1);
  }
  if (num2 % 2 == 0) {
    printf("%d is even\n", num2);
  } else {
    printf("%d is odd\n", num2);
  }
  if (num3 % 2 == 0) {
    printf("%d is even\n", num3);
  } else {
    printf("%d is odd\n", num3);
  }
  return 0;
}