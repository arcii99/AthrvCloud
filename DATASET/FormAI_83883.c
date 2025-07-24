//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void binaryConverter(int num) {
  int binary[32];
  int index = 0;

  while (num > 0) {
    binary[index] = num % 2;
    num = num / 2;
    index++;
  }

  for (int i = index - 1; i >= 0; i--) {
    printf("%d", binary[i]);
  }
}

int main() {
  int num;

  printf("Enter a decimal number to convert to binary: ");
  scanf("%d", &num);

  printf("Binary conversion is: ");
  binaryConverter(num);

  return 0;
}