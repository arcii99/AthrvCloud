//FormAI DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>

/* Function to find maximum of two numbers */
int max(int a, int b) {
   return (a > b) ? a : b;
}

/* Function to find minimum of two numbers */
int min(int a, int b) {
   return (a < b) ? a : b;
}

/* Function to find greatest common divisor of two numbers */
int gcd(int a, int b) {
   int temp = 0;
   while (b != 0) {
      temp = b;
      b = a % b;
      a = temp;
   }
   return a;
}

/* Function to find least common multiple of two numbers */
int lcm(int a, int b) {
   return (a*b)/gcd(a, b);
}

int main() {
   int a = 18, b = 24;

   printf("Maximum of %d and %d is %d\n", a, b, max(a, b));
   printf("Minimum of %d and %d is %d\n", a, b, min(a, b));
   printf("Greatest Common Divisor of %d and %d is %d\n", a, b, gcd(a, b));
   printf("Least Common Multiple of %d and %d is %d\n", a, b, lcm(a, b));

   return 0;
}