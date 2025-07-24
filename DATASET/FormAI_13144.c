//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>

int main() {
  int decimal, remainder;
  char hexadecimal[16];
  int i = 0, j;

  printf("Enter Decimal Number: ");
  scanf("%d", &decimal);

  while (decimal != 0){
    remainder = decimal % 16;
    if (remainder < 10){
      hexadecimal[i] = remainder + 48;
      i++;
    }
    else {
      hexadecimal[i] = remainder + 55;
      i++;
    }
    decimal /= 16;
  }

  printf("\nHexadecimal Number: ");

  for (j = i - 1; j >= 0; j--)
    printf("%c", hexadecimal[j]);

  printf("\n");
  return 0;
}