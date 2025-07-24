//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>

int main() {
   int num1, num2, sum, difference, product, quotient, modulus;

   printf("Enter two numbers: ");
   scanf("%d %d", &num1, &num2);

   // Arithmetic Operations
   sum = num1 + num2;
   difference = num1 - num2;
   product = num1 * num2;
   quotient = num1 / num2;
   modulus = num1 % num2;

   // Output
   printf("Sum: %d\n",sum);
   printf("Difference: %d\n",difference);
   printf("Product: %d\n",product);
   printf("Quotient: %d\n",quotient);
   printf("Modulus: %d\n",modulus);

   // Intelligent Output
   if(num1 == num2) {
      printf("The numbers are equal.\n");
   } else if(num1 > num2) {
      printf("%d is larger.\n", num1);
   } else {
      printf("%d is larger.\n", num2);
   }

   if(quotient * num2 == num1) { // Check if num1 is divisible by num2 completely
      printf("%d is divisible by %d.\n",num1,num2);
   } else {
      printf("%d is not divisible by %d.\n",num1,num2);
   }

   if(sum % 2 == 0) { // Check if sum is even
      printf("%d is even.\n",sum);
   } else {
      printf("%d is odd.\n",sum);
   }

   return 0;
}