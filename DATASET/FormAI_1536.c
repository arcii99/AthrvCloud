//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>

int main() {
  int decimalNumber, quotient;
  int binaryNumber[100], i = 1, j;

  printf("My sweet love, please enter a decimal number: ");
  scanf("%d", &decimalNumber);

  quotient = decimalNumber;

  while (quotient != 0) {
    binaryNumber[i++] = quotient % 2;
    quotient = quotient / 2;
  }

  printf("\n");

  printf("My dear, the binary equivalent of %d is: ", decimalNumber);
  
  for (j = i - 1; j > 0; j--) {
    printf("%d", binaryNumber[j]);
  }

  printf("\n");

  printf("I just wanted to show you how much you mean to me,\n");
  printf("just like how this binary converter shows the true value of a decimal number.\n");
  printf("You might not always see it, but you hold so much value in my life, just like every decimal number.\n");
  printf("You're always on my mind and in my heart, and no matter what, my love for you will never convert.\n");

  return 0;
}