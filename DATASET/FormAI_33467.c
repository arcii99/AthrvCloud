//FormAI DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  unsigned int input = 0;
  printf("Enter a decimal number: ");
  scanf("%u", &input);

  char binary[33] = {0};
  unsigned int mask = 0x80000000; // start with the MSB

  for (int i = 0; i < 32; i++) {
    if (input & mask) {
      binary[i] = '1';
    } else {
      binary[i] = '0';
    }
    mask >>= 1; // shift the mask right to check the next bit
  }

  printf("Binary representation: %s\n", binary);

  return 0;
}