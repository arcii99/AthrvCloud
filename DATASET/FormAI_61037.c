//FormAI DATASET v1.0 Category: Recursive ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Let's write a program to calculate the factorial of a given number.

int factorial(int num) {

   // Before we dive into the method, let's define the base case.
   if (num == 0) {
      return 1;
   } else {
      return num * factorial(num - 1);
   }
}

int main() {

   int num, result;

   // Let's ask the user to enter a number.
   printf("Enter a positive integer number: ");
   scanf("%d", &num);

   // Let's check if the number is less than zero.
   if (num < 0) {
      printf("Error! Factorial of negative numbers is not possible.\n");
      return 0;
   } else {
      
      // Let's call our recursive method and print out the result.
      result = factorial(num);
      printf("The factorial of %d is %d.\n", num, result);
   }

   return 0;
}