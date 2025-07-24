//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>

char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void toHexadecimal(int num) {
  int quotient = num / 16;
  int remainder = num % 16;

  if (quotient != 0) {
    toHexadecimal(quotient);
  }
  printf("%c", hexDigits[remainder]);
}

int main() {
  int decimal = 255;

  printf("Decimal %d in hexadecimal is 0x", decimal);
  toHexadecimal(decimal);
  printf("\n");

  return 0;
}