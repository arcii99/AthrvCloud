//FormAI DATASET v1.0 Category: Recursive ; Style: high level of detail
/* This is a program that calculates the n-th Fibonacci Number using
   recursive method */
#include <stdio.h>

/* Function prototype declaration */
int fibonacci(int n);

/* Main function */
int main(void) {
   int n;
   
   printf("Enter a positive integer n: ");
   scanf("%d",&n);
   
   printf("The %d-th Fibonacci number is: %d\n",n,fibonacci(n));
   
   return 0;
}

/* Recursive function definition */
int fibonacci(int n) {

   if(n==1) /* Base case */
      return 0;
   else if(n==2) /* Base case */
      return 1;
   else /* Recursive case */
      return fibonacci(n-1)+fibonacci(n-2);
}