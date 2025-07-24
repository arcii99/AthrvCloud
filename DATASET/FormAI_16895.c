//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>

int factorial(int n) {
   if(n == 1) {
      return n;
   } else {
      return n * factorial(n-1);
   }
}

int main() {
   int num = 5;
   int fact = factorial(num);
   printf("Factorial of %d is %d", num, fact);
   return 0;
}