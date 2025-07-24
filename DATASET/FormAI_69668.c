//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void hexConverter(int decimalNum) {
  int remainder, quotient;
  char hexNum[50];
  int i = 0;

  quotient = decimalNum;

  while (quotient != 0) {
    remainder = quotient % 16;

    if (remainder < 10)
      hexNum[i++] = 48 + remainder;
    else
      hexNum[i++] = 55 + remainder;

    quotient = quotient / 16;
  }

  printf("Hexadecimal number is: ");
  for (int j = i - 1; j >= 0; j--)
    printf("%c", hexNum[j]);
}

int main() {
  int decimalNum;

  printf("Enter a decimal number: ");
  scanf("%d", &decimalNum);

  hexConverter(decimalNum);

  return 0;
}