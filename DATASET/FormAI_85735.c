//FormAI DATASET v1.0 Category: Scientific ; Style: complex
#include <stdio.h>

// function to calculate factorial of a number
int factorial(int num) {
   if(num == 1) {
       return 1;
   }
   return num * factorial(num - 1);
}

// function to calculate power of a number
int power(int base, int exp) {
   if(exp==0) {
       return 1;
   }
   return base * power(base, exp-1);
}

// main function
int main() {
   int n, i, j;
   float f, sum;
   
   printf("Enter a number: ");
   scanf("%d", &n);
   
   // calculate n!
   int fact = factorial(n);
   
   // calculate sum of series
   for(i=1; i<=n; i++) {
       float term = 1.0/power(i,i);
       sum += term;
   }
   
   // print result
   printf("\n Factorial of %d is: %d", n, fact);
   printf("\n Sum of series is: %f", sum);
   
   return 0;
}