//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>

int main() {
  int decimalNumber, quotient, remainder;
  int i, j = 0;
  char hexadecimalNumber[100];

  printf("Enter an integer: ");
  scanf("%d", &decimalNumber);
  
  quotient = decimalNumber;

  while (quotient != 0) {
    remainder = quotient % 16;
    
    if (remainder < 10)
      hexadecimalNumber[j++] = 48 + remainder;   // ASCII code for 0 to 9
    else
      hexadecimalNumber[j++] = 55 + remainder;   // ASCII code for A to F

    quotient /= 16;
  }

  printf("Hexadecimal number of %d is: ", decimalNumber);
  
  for (i = j - 1; i >= 0; i--)
    printf("%c", hexadecimalNumber[i]);

  return 0;
}