//FormAI DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>

int main() {
  int decimalNum, binaryNum = 0, base = 1, remainder;
  
  printf("Enter a decimal number: ");
  scanf("%d", &decimalNum);
  
  while (decimalNum > 0) {
    remainder = decimalNum % 2;
    binaryNum += remainder * base;
    decimalNum /= 2;
    base *= 10;
  }
  
  printf("The binary equivalent is: %d", binaryNum);

  return 0;
}