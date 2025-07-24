//FormAI DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>

int main() {
  int decimalNumber;
  int remainder[20];
  int i = 0;

  printf("Enter a decimal number: ");
  scanf("%d", &decimalNumber);

  // converter loop
  while(decimalNumber != 0) {
    remainder[i] = decimalNumber%2;
    decimalNumber = decimalNumber/2;
    i++;
  }

  // printing binary conversion
  printf("Binary conversion: ");
  for(int j = i - 1; j >= 0; j--) {
    printf("%d", remainder[j]);
  }

  // printing extra newline
  printf("\n");

  return 0;
}