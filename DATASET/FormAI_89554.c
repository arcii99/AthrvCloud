//FormAI DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>

void decimalToBinary(int dec_num) {
  int binary_number[32];
  int i = 0;
  while (dec_num > 0) {
    binary_number[i] = dec_num % 2;
    dec_num = dec_num / 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary_number[j]);
  }
}

int main() {
  int dec_num;
  printf("Enter a decimal number: ");
  scanf("%d", &dec_num);
  printf("The binary equivalent of %d is: ", dec_num);
  decimalToBinary(dec_num);
  printf("\n");
  return 0;
}