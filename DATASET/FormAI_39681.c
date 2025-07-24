//FormAI DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>

int main() {
   int num, binaryNum = 0, remainder, base = 1;

   printf("Enter a decimal number: ");
   scanf("%d", &num);

   while (num != 0) {
      remainder = num % 2; // find the remainder
      binaryNum += remainder * base; // add the remainder to the binary number
      num /= 2; // divide the decimal number by 2
      base *= 10; // move the base by a factor of 10
   }

   printf("The binary equivalent of %d is %d.", num, binaryNum);

   return 0;
}