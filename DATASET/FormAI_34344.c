//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

int main() {
  int num1, num2, sum, sub, mul;
  float div;

  printf("Enter two numbers separated by space: ");
  scanf("%d %d", &num1, &num2);

  sum = num1 + num2;
  sub = num1 - num2;
  mul = num1 * num2;

  if (num2 == 0) {
    printf("Cannot divide by zero\n");
  } else {
    div = (float) num1/num2;
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, sub);
    printf("%d * %d = %d\n", num1, num2, mul);
    printf("%d / %d = %.2f\n", num1, num2, div);
  }

  return 0;
}