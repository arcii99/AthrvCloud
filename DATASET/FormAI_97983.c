//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>

int main() {
   int num1, num2, result;
   printf("Enter first number: ");
   scanf("%d", &num1);
   printf("Enter second number: ");
   scanf("%d", &num2);
   // add the two numbers together
   result = num1 + num2;
   printf("The sum of %d and %d is %d\n", num1, num2, result);
   // subtract the second number from the first number
   result = num1 - num2;
   printf("%d minus %d is %d\n", num1, num2, result);
   // multiply the two numbers together
   result = num1 * num2;
   printf("The product of %d and %d is %d\n", num1, num2, result);
   // divide the first number by the second number
   if (num2 != 0) {
       result = num1 / num2;
       printf("%d divided by %d is %d\n", num1, num2, result);
   } else {
       printf("Cannot divide by zero\n");
   }
   // take the modulus of the first number and the second number
   if (num2 != 0) {
       result = num1 % num2;
       printf("%d modulus %d is %d\n", num1, num2, result);
   } else {
       printf("Cannot find modulus with zero\n");
   }
   // increment the first number
   num1++;
   printf("Incrementing the first number gives %d\n", num1);
   // decrement the second number
   num2--;
   printf("Decrementing the second number gives %d\n", num2);
   return 0;
}