//FormAI DATASET v1.0 Category: Recursive ; Style: light-weight
#include<stdio.h>

int factorial(int n) {
   if(n == 0) 
      return 1;
   else 
      return n * factorial(n-1);
}

int fibonacci(int n) {
   if(n == 0) 
      return 0;
   else if(n == 1) 
      return 1;
   else 
      return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
   int n, option, result;
   printf("Select an option:\n");
   printf("1. Find factorial\n");
   printf("2. Find n-th Fibonacci number\n");
   scanf("%d", &option);

   switch(option) {
      case 1:
         printf("Enter a number:\n");
         scanf("%d", &n);
         result = factorial(n);
         printf("Factorial of %d is %d", n, result);
         break;

      case 2:
         printf("Enter a number:\n");
         scanf("%d", &n);
         result = fibonacci(n);
         printf("%d-th Fibonacci number is %d", n, result);
         break;

      default:
         printf("Invalid option");
         break;
   }

   return 0;
}