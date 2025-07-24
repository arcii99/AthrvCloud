//FormAI DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>

int main() {
   int num1, num2, sum, difference, product;
   float quotient;

   printf("Enter first integer: ");
   scanf("%d", &num1);

   printf("Enter second integer: ");
   scanf("%d", &num2);

   sum = num1 + num2;
   difference = num1 - num2;
   product = num1 * num2;

   if (num2 != 0) {
      quotient = (float)num1 / num2;
   } else {
      printf("Error: Division by 0\n");
   }

   printf("\n**** Arithmetic Operations ****\n");
   printf("%d + %d = %d\n", num1, num2, sum);
   printf("%d - %d = %d\n", num1, num2, difference);
   printf("%d * %d = %d\n", num1, num2, product);

   if (num2 != 0) {
      printf("%d / %d = %.2f\n", num1, num2, quotient);
   }

   printf("\n**** Bitwise Operations ****\n");
   printf("%d & %d = %d\n", num1, num2, num1&num2);
   printf("%d | %d = %d\n", num1, num2, num1|num2);
   printf("%d ^ %d = %d\n", num1, num2, num1^num2);
   printf("~%d = %d\n", num1, ~num1);
   printf("~%d = %d\n", num2, ~num2);

   printf("\n**** Shift Operations ****\n");
   printf("%d << 2 = %d\n", num1, num1<<2);
   printf("%d >> 2 = %d\n", num1, num1>>2);
   printf("%d << 3 = %d\n", num2, num2<<3);
   printf("%d >> 3 = %d\n", num2, num2>>3);

   return 0;
}