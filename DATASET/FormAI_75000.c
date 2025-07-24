//FormAI DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
  int decimal_number, binary_number = 0, i = 0;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal_number);

  while (decimal_number != 0) {
    binary_number += (decimal_number % 2) * pow(10, i);
    decimal_number /= 2;
    i++;
  }
  printf("Binary equivalent: %d", binary_number);

  return 0;
}