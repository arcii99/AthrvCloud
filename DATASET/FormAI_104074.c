//FormAI DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  char binary[100];
  int decimal = 0;
  int i = 0, len = 0, j = 0;

  printf("Enter a binary number: ");
  scanf("%s", binary);

  len = strlen(binary);
  
  for (i = len - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      decimal += pow(2, j);
    }
    j++;
  }
  
  printf("Decimal equivalent: %d\n", decimal);
  
  return 0;
}