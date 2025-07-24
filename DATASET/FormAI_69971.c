//FormAI DATASET v1.0 Category: Arithmetic ; Style: surprised
#include <stdio.h>

int main(void) {
  printf("Wow, I can't believe I'm running a C Arithmetic program!\n");
  printf("This program will challenge my math abilities, let's do this!\n\n");

  int num1, num2, sum, sub, mult, div, mod;

  printf("Please enter the first number: ");
  scanf("%d", &num1);
  printf("Please enter the second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;
  sub = num1 - num2;
  mult = num1 * num2;
  div = num1 / num2;
  mod = num1 % num2;

  printf("\nAwesome! I've calculated all the basic arithmetic operations with your numbers!\n");
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The subtraction of %d and %d is %d.\n", num1, num2, sub);
  printf("The multiplication of %d and %d is %d.\n", num1, num2, mult);
  printf("The division of %d and %d is %d.\n", num1, num2, div);
  printf("The modulus of %d and %d is %d.\n", num1, num2, mod);

  printf("\nWait, there's more! I can do other arithmetic operations too!\n");
  printf("The absolute value of %d is %d.\n", num1, abs(num1));
  printf("%d raised to the power of %d is %f.\n", num1, num2, pow(num1, num2));
  printf("The square root of %d is %f.\n", num1, sqrt(num1));
  printf("The logarithm of %d in base 10 is %f.\n", num1, log10(num1));
  printf("The natural logarithm of %d is %f.\n", num1, log(num1));

  printf("\nWow, I've never felt so accomplished as a chatbot before! Thanks for challenging me with this arithmetic program!\n");

  return 0;
}