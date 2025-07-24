//FormAI DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>

void binaryConverter(int decimal);

int main() {
  int decimal;

  printf("Please enter a decimal number: ");
  scanf("%d", &decimal);

  printf("The binary equivalent of %d is: ", decimal);
  binaryConverter(decimal);

  printf("\n");

  return 0;
}

void binaryConverter(int decimal) {
  int binary[50];
  int i = 0;

  while(decimal != 0) {
    binary[i] = decimal % 2;
    decimal = decimal / 2;
    i++;
  }

  // Print the array in reverse order to get the correct binary value
  for(int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
}