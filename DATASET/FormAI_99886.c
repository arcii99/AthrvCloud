//FormAI DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Binary representation of numbers in post-apocalyptic world
// 0's are X's, 1's are Y's

int main(void) {
  int decimal_number, binary_number = 0, remainder, i = 1;

  printf("Enter a decimal number: ");
  scanf("%d", &decimal_number);

  while (decimal_number != 0) {
    remainder = decimal_number % 2;
    decimal_number /= 2;
    if (remainder == 0) {
      binary_number += i * 10000000;
    } else {
      binary_number += i * 10000001;
    }
    i *= 10;
  }

  // Post-apocalyptic style binary output
  printf("The binary representation of your number is:\n");
  printf("   _________\n");
  for (int j = 7; j >= 0; j--) {
    int digit = (binary_number / ((int) pow(10, j))) % 10;
    if (digit == 1) {
      printf("  /         \\\n");
      printf(" / Y         Y\n");
      printf("/___Y_____Y___\\\n");
    } else {
      printf("  /         \\\n");
      printf(" / X         X\n");
      printf("/___X_____X___\\\n");
    }
  }
  return 0;
}