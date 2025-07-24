//FormAI DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>

void decimalToBinary(unsigned int decimal) {
  unsigned int binary[32]; // maximum 32-bit binary number
  int i = 0;

  while (decimal > 0) {
    binary[i++] = decimal % 2;
    decimal /= 2;
  }

  printf("Binary conversion: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
}

int main() {
  printf("Please enter a decimal number: ");
  unsigned int decimal;
  scanf("%u", &decimal);

  decimalToBinary(decimal);

  return 0;
}