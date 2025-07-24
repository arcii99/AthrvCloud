//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>

int main(void) {
  unsigned int decimalNum = 0;
  char hexNum[8];
  int i = 0, remainder = 0;

  printf("Enter a decimal number to convert to hexadecimal: ");
  scanf("%u", &decimalNum);

  while (decimalNum != 0) {
    remainder = decimalNum % 16;

    if (remainder < 10) {
      hexNum[i] = remainder + 48;
      i++;
    } else {
      hexNum[i] = remainder + 55;
      i++;
    }

    decimalNum /= 16;
  }

  // printing the hexadecimal number in reverse order
  printf("The hexadecimal number is: ");
  for (int j = i - 1; j >= 0; j--)
    printf("%c", hexNum[j]);

  printf("\n");

  return 0;
}