//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

int main() {
  int num1, num2, num3, num4, sum;

  printf("Enter four numbers: ");
  scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

  sum = num1 + num2 + num3 + num4;

  printf("The sum of the numbers is %d.\n", sum);

  int product = num1 * num2 * num3 * num4;
  printf("The product of the numbers is %d.\n", product);

  float average = (float)sum / 4;
  printf("The average of the numbers is %.2f.\n", average);

  int remainder = product % sum;
  printf("The remainder of the product divided by the sum is %d.\n", remainder);

  int difference = num1 - num2 - num3 - num4;
  printf("The difference of the numbers is %d.\n", difference);

  return 0;
}