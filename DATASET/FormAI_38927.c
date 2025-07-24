//FormAI DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
   int base, exponent, result;
   printf("Enter a base number: ");
   scanf("%d", &base);
   printf("Enter an exponent: ");
   scanf("%d", &exponent);

   result = pow(base, exponent);

   printf("%d^%d = %d\n", base, exponent, result);

   return 0;
}