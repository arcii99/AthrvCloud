//FormAI DATASET v1.0 Category: Arithmetic ; Style: automated
#include <stdio.h>

int main() {
   int num1, num2, sum, sub, mul;
   float div, mod;
   
   printf("Enter the first number: ");
   scanf("%d", &num1);
   
   printf("Enter the second number: ");
   scanf("%d", &num2);
   
   sum = num1 + num2;
   sub = num1 - num2;
   mul = num1 * num2;
   
   if(num2 != 0) {
       div = num1 / (float)num2;
       mod = num1 % num2;
   }
   
   printf("The sum of %d and %d is: %d\n", num1, num2, sum);
   printf("The difference between %d and %d is: %d\n", num1, num2, sub);
   printf("The product of %d and %d is: %d\n", num1, num2, mul);
   
   if(num2 != 0) {
       printf("%d divided by %d is: %.2f\n", num1, num2, div);
       printf("The remainder when %d is divided by %d is: %.0f\n", num1, num2, mod);
   } else {
       printf("Undefined.\n");
   }
   
   return 0;
}