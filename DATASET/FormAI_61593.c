//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>

int main() {
  unsigned long dec, bin = 0, base = 1;
  
  printf("Enter a decimal number: ");
  scanf("%lu", &dec);
  
  while (dec > 0) {
    bin += (dec % 2) * base;
    dec /= 2;
    base *= 10;
  }
  
  printf("Binary equivalent is: %lu\n", bin);

  return 0;
}