//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  char input[1024];
  int decimal;
  char hexadecimal[1024];

  // User Input
  printf("Enter a decimal number: ");
  fgets(input, 1024, stdin);
  decimal = atoi(input);

  // Decimal to Hexadecimal Conversion
  int quotient, remainder;
  int i = 0;
  quotient = decimal;

  while(quotient != 0) {
    remainder = quotient % 16;
    if(remainder < 10)
      hexadecimal[i++] = 48 + remainder;
    else
      hexadecimal[i++] = 55 + remainder;
    quotient = quotient / 16;
  }
  hexadecimal[i] = '\0';

  // Output
  printf("\n*****************************************\n\n");
  printf("DECIMAL: %d\n", decimal);
  printf("HEXADECIMAL: ");
  for(int j = i - 1; j >= 0; j--) {
    printf("%c", hexadecimal[j]);
    if(j % 2 == 0)
      printf(" ");
    if(j % 4 == 0)
      printf("  ");
  }
  printf("\n\n*****************************************\n");

  return 0;
}