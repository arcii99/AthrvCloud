//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>

int main(void) {
  char input[20];
  printf("Welcome to the Hexadecimal Converter Program. Please enter a decimal number to convert to Hexadecimal: ");
  fgets(input, sizeof(input), stdin);
  int decimal = atoi(input);

  char hex[100];
  int i = 0;
  while (decimal != 0) {
    int remainder = decimal % 16;
    if (remainder < 10) {
      hex[i] = remainder + 48; // ASCII code for 0-9
    } else {
      hex[i] = remainder + 55; // ASCII code for A-F
    }
    i++;
    decimal /= 16;
  }
  hex[i] = '\0';

  printf("The decimal number in hexadecimal is: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%c", hex[j]);
  }

  printf("\n");

  return 0;
}