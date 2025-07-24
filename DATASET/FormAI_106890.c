//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hello friend! I'm a cheerful C arithmetic program!\n");
  printf("Let's calculate something fun together!\n");

  int num1, num2;
  printf("Enter two numbers to add: ");
  scanf("%d %d", &num1, &num2);
    
  int sum = num1 + num2;
  printf("The sum of %d and %d is: %d\n", num1, num2, sum);

  int num3, num4;
  printf("Enter two numbers to subtract: ");
  scanf("%d %d", &num3, &num4);

  int diff = num3 - num4;
  printf("The difference between %d and %d is: %d\n", num3, num4, diff);

  int num5, num6;
  printf("Enter two numbers to multiply: ");
  scanf("%d %d", &num5, &num6);

  int prod = num5 * num6;
  printf("The product of %d and %d is: %d\n", num5, num6, prod);

  int num7, num8;
  printf("Enter two numbers to divide: ");
  scanf("%d %d", &num7, &num8);

  if (num8 == 0) {
    printf("Oops! Division by zero is undefined!\n");
  } else {
      float quotient = (float) num7 / num8;
      printf("The quotient of %d and %d is: %.2f\n", num7, num8, quotient);
  }

  printf("Thanks for using this program! Have a great day!\n");
  return 0;
}