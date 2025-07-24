//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>

int main() {
   int num1, num2, sum, diff, prod, div, remainder;
   
   printf("Enter two integers: ");
   scanf("%d %d", &num1, &num2);

   sum = num1 + num2;
   diff = num1 - num2;
   prod = num1 * num2;
   div = num1 / num2;
   remainder = num1 % num2;
   
   printf("Sum of the entered integers = %d\n", sum);
   printf("Difference of the entered integers = %d\n", diff);
   printf("Product of the entered integers = %d\n", prod);
   printf("Quotient of the entered integers = %d\n", div);
   printf("Remainder of the entered integers = %d\n", remainder);

   return 0;
}