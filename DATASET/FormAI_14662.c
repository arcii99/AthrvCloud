//FormAI DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>

int main() {
  int decimal;
  printf("Welcome to the Binary Converter!\n");
  printf("Enter a decimal number to convert to binary: ");
  scanf("%d", &decimal);

  int binary[32]; // we'll assume 32-bit integers
  int i = 0;

  // calculate the binary representation of the decimal number
  while (decimal > 0) {
    binary[i] = decimal % 2;
    decimal /= 2;
    i++;
  }

  // print out the binary representation in reverse
  printf("The binary representation of your number is: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
  printf("\n");

  return 0;
}