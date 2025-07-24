//FormAI DATASET v1.0 Category: Scientific ; Style: minimalist
#include <stdio.h>

int main() {
   int num1, num2, result;
   
   printf("Enter first number: ");
   scanf("%d", &num1);

   printf("Enter second number: ");
   scanf("%d", &num2);
   
   result = gcd(num1, num2);
   
   printf("GCD of %d and %d is %d.\n", num1, num2, result);
   
   return 0;
}

int gcd(int x, int y) {
   int r;
   
   while (y != 0) {
      r = x % y;
      x = y;
      y = r;
   }
   
   return x;
}