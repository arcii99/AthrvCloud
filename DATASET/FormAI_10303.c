//FormAI DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>

int main() {
   int decimalNumber;
   long int binaryNumber = 0, j = 1, remainder;

   printf("Enter a decimal number: ");
   scanf("%d", &decimalNumber);

   while (decimalNumber != 0) {
      remainder = decimalNumber % 2;
      binaryNumber += remainder * j;
      j *= 10;
      decimalNumber /= 2;
   }

   printf("Binary representation of %d is %ld", decimalNumber, binaryNumber);
   
   return 0;
}