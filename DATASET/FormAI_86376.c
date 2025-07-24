//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>

int main() {
  int decimal, binary = 0, base = 1, rem;

  printf("Enter the Decimal number: ");
  scanf("%d", &decimal);

  while (decimal > 0) {
    rem = decimal % 2;
    binary = binary + (rem * base);
    decimal = decimal / 2;
    base = base * 10;
  }

  printf("The Binary value is: %d", binary);

  return 0;
}