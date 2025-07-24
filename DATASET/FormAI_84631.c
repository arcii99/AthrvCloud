//FormAI DATASET v1.0 Category: Recursive ; Style: expert-level
#include<stdio.h>

int gcd (int a, int b) {
   // Base case
   if (b == 0) {
      return a;
   }

   // Recursive case
   return gcd(b, a % b);
}

int main () {
   int num1, num2;

   // Read inputs
   printf("Enter two numbers: ");
   scanf("%d %d", &num1, &num2);

   // Find gcd of given numbers
   int result = gcd(num1, num2);

   // Print result
   printf("GCD of %d and %d is %d\n", num1, num2, result);

   return 0;
}