//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>

int main() {
   int num1 = 10, num2 = 20, result;
   float num3 = 2.5, num4 = 3.5, answer;

   //addition
   result = num1 + num2;
   printf("Addition: %d\n", result);

   //subtraction
   result = num2 - num1;
   printf("Subtraction: %d\n", result);

   //multiplication
   result = num1 * num2;
   printf("Multiplication: %d\n", result);

   //division
   answer = num2 / num1;
   printf("Division: %.2f\n", answer);

   //modulus
   result = num2 % num1;
   printf("Modulus: %d\n", result);

   //increment
   num1++;
   printf("Increment: %d\n", num1);

   //decrement
   num2--;
   printf("Decrement: %d\n", num2);

   //mixed operations
   answer = (num1 * num3) + (num2 / num4);
   printf("Mixed Operations: %.2f\n", answer);

   return 0;
}