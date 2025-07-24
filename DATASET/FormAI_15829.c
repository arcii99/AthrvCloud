//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>

int main() {
  unsigned int decimal;
  char hex[100];
  int i = 0;

  // Prompt the user to enter a decimal number
  printf("My dearest, please enter a decimal number: ");
  scanf("%u", &decimal);

  // Conversion from decimal to hexadecimal
  while (decimal > 0) {
    int remainder = decimal % 16;
    if (remainder < 10) {
      hex[i++] = remainder + 48;
    } else {
      hex[i++] = remainder + 55;
    }
    decimal = decimal / 16;
  }
  hex[i] = '\0';

  // Reverse the order of the resulting hexadecimal number
  int j, k;
  char temp;
  for (j = 0, k = i - 1; j < k; j++, k--) {
    temp = hex[j];
    hex[j] = hex[k];
    hex[k] = temp;
  }

  // Display the resulting hexadecimal number
  printf("Oh my angel, your decimal number in hexadecimal is: %s.\n", hex);
  printf("I am impressed by the number you have entered and cannot get enough of it.\n");
  return 0;
}