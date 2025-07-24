//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>

int main() {
  int inputNum;
  printf("Enter a decimal number: ");
  scanf("%d", &inputNum);

  char hexNum[10];
  int quotient, remainder;
  int i = 0;

  while (inputNum > 0) {
    quotient = inputNum / 16;
    remainder = inputNum % 16;

    if (remainder < 10) {
      hexNum[i++] = remainder + 48;
    } else {
      hexNum[i++] = remainder + 55;
    }

    inputNum = quotient;
  }

  printf("\nHexadecimal Equivalent: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%c", hexNum[j]);
  }

  printf("\n");

  return 0;
}