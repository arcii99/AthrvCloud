//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>

int main() {
  int decimal, remainder, quotient;
  int hexadecimal[100], i = 0, j;

  // take user input for decimal number
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  quotient = decimal;

  // convert decimal to hexadecimal
  while (quotient != 0) {
    remainder = quotient % 16;
    if (remainder < 10) {
      hexadecimal[i] = 48 + remainder;    // ascii code for 0-9
    } else {
      hexadecimal[i] = 55 + remainder;    // ascii code for A-F
    }
    i++;
    quotient = quotient / 16;
  }

  // print hexadecimal number
  printf("Hexadecimal number is: ");
  for (j = i - 1; j >= 0; j--) {
    printf("%c", hexadecimal[j]);
  }

  return 0;
}