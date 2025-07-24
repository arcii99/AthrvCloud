//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>

void printNumbers(int n) {
   if (n <= 0) {
      return;
   } else {
      printf("%d\n", n);
      printNumbers(n-1);
   }
}

int factorial(int n) {
   if (n == 0) {
      return 1;
   } else {
      return n * factorial(n-1);
   }
}

int sumDigits(int n) {
   if (n == 0) {
      return 0;
   } else {
      return n % 10 + sumDigits(n/10);
   }
}

int main() {
   int num;

   printf("Enter a positive integer: ");
   scanf("%d", &num);

   printf("Printing numbers from %d down to 1:\n", num);
   printNumbers(num);

   printf("\nFactorial of %d is: %d", num, factorial(num));

   printf("\nSum of digits of %d is: %d", num, sumDigits(num));

   return 0;
}