//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define variables
  int decimal, binary[32], index = 0;

  // Ask for user input
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert decimal to binary
  while(decimal > 0) {
    binary[index] = decimal % 2;
    decimal = decimal / 2;
    index++;
  }

  // Output binary number
  printf("Binary representation: ");
  for(int i = index - 1; i >= 0; i--) {
    printf("%d", binary[i]);
  }

  // Exit program
  return 0;
}