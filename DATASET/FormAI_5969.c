//FormAI DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>

int main() {
  printf("Welcome to C Binary Converter!\n");
  printf("Enter a decimal number to convert to binary: ");
  
  int decimal;
  scanf("%d", &decimal);
  
  int binary[32];
  int index = 0;

  while(decimal > 0) {
    binary[index] = decimal % 2;
    decimal = decimal / 2;
    index++;
  }

  printf("Binary: ");
  for(int i = index - 1; i >= 0; i--) {
    printf("%d", binary[i]);
  }

  printf("\n");

  return 0;
}