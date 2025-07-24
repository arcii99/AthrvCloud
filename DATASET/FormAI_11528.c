//FormAI DATASET v1.0 Category: Binary Converter ; Style: random
// Welcome to the C Binary Converter!
// This program will take in a decimal number
// and convert it to binary.

#include <stdio.h>
#include <stdlib.h>

int main() {
  int decimal, binary = 0, base = 1, remainder;

  // Prompt user for input
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert decimal to binary
  while (decimal > 0) {
    remainder = decimal % 2;
    binary = binary + remainder * base;
    decimal = decimal / 2;
    base = base * 10;
  }

  // Display the binary number
  printf("The binary conversion of %d is %d.\n", decimal, binary);

  // Bonus feature: convert binary back to decimal and display it
  int newDecimal = 0, i = 1, lastDigit;

  while (binary > 0) {
    lastDigit = binary % 10;
    binary = binary / 10;
    newDecimal = newDecimal + lastDigit * i;
    i = i * 2;
  }

  printf("And the reverse conversion of %d is %d.\n", binary, newDecimal);

  return 0;
}