//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>

int main()
{
  int decimalNumber, remainder, binaryNumber = 0, base = 1;

  printf("Enter a decimal number: ");
  scanf("%d", &decimalNumber);

  while (decimalNumber > 0)
  {
    remainder = decimalNumber % 2;
    binaryNumber += remainder * base;
    decimalNumber /= 2;
    base *= 10;
  }

  printf("Binary Number: %d", binaryNumber);

  return 0;
}