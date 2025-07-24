//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
  int decimal, binary[32], i = 0, j;
  
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);
  
  // Convert decimal to binary
  while (decimal > 0) {
    binary[i] = decimal % 2;
    decimal /= 2;
    i++;
  }
  
  // Print binary representation
  printf("Binary equivalent: ");
  for (j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
  printf("\n");
  
  return EXIT_SUCCESS;
}