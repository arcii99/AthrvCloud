//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>

void decimalToHexadecimal(int decimalNumber) {
  int quotient, i = 1, j, temp;
  char hexadecimalNumber[100];

  quotient = decimalNumber;

  while (quotient != 0) {
    temp = quotient % 16;

    if (temp < 10) {
      temp += 48;
    } else {
      temp += 55;
    }

    hexadecimalNumber[i++] = temp;
    quotient /= 16;
  }

  printf("Hexadecimal number of %d is: ", decimalNumber);

  for (j = i - 1; j > 0; j--) {
    printf("%c", hexadecimalNumber[j]);
  }

  printf("\n");
}

int main() {
  int decimalNumber;

  printf("Enter a decimal number: ");
  scanf("%d", &decimalNumber);

  decimalToHexadecimal(decimalNumber);

  return 0;
}