//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

int main() {

  int num1 = 7, num2 = 12, num3 = 22, num4 = 3, result;

  printf("Get ready to witness the power of arithmetic calculations!\n");

  result = num1 + num2;
  printf("The sum of %d and %d is %d. Are you ready for more?\n", num1, num2, result);

  result = num3 - num1;
  printf("Subtracting %d from %d gives us %d. I hope you still have your seatbelts on!\n", num1, num3, result);

  result = num4 * num1;
  printf("%d multiplied by %d gives us %d. Are you still following me?\n", num1, num4, result);

  result = num3 / num2;
  printf("When we divide %d by %d, we get %d. This is so much fun!\n", num3, num2, result);

  result = num3 % num4;
  printf("The remainder when %d is divided by %d is %d. This really is amazing, isn't it?\n", num3, num4, result);

  printf("Now brace yourself for some more complex calculations!\n");

  result = num1 + num2 - num3 * num4;
  printf("The result of %d plus %d minus %d multiplied by %d is %d. Marvelous!\n", num1, num2, num3, num4, result);

  result = (num1 + num2) * (num3 - num4);
  printf("The result of (%d plus %d) multiplied by (%d minus %d) is %d. Astonishing!\n", num1, num2, num3, num4, result);

  return 0;
}