//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
/*Program to implement Euclid's Algorithm for finding the greatest common divisor */
#include <stdio.h>

void main() {

   int num1, num2;

   printf("Please enter the first number: ");
   scanf("%d", &num1);
   printf("Please enter the second number: ");
   scanf("%d", &num2);

   int remainder = num1 % num2; 
   while (remainder != 0) {
      num1 = num2;
      num2 = remainder;
      remainder = num1 % num2;
   }

   printf("The GCD of the two numbers is %d\n", num2);
}