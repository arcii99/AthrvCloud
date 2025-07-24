//FormAI DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int decimalNumber, tempDecimalNumber, binaryNumber = 0, base = 1, remainder;

  printf("Enter an integer in decimal number system: ");
  scanf("%d", &decimalNumber);

  tempDecimalNumber = decimalNumber;

  while (tempDecimalNumber > 0) {
    remainder = tempDecimalNumber % 2;
    binaryNumber = binaryNumber + remainder * base;
    base = base * 10;
    tempDecimalNumber = tempDecimalNumber / 2;
  }

  printf("The binary equivalent of %d is %d\n", decimalNumber, binaryNumber);
  
  return 0;
}