//FormAI DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {

  int num;
  printf("Enter a decimal number: ");
  scanf("%d", &num);
  char binary[32] = {0}; // create an array to store binary number with max length of 32 bits
  int index = 0; // keep track of array index
  while (num > 0) {
    int remainder = num % 2;
    binary[index++] = remainder + '0'; // add binary digit to array
    num /= 2;
  }
  printf("\nBinary equivalent: ");
  for (int i = index - 1; i >= 0; i--) {
    printf("%c", binary[i]); // print binary number in correct order
  }
  printf("\n");
  return 0;
}