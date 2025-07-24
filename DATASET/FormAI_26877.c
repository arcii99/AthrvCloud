//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int dec, rem, len = 0, i = 0;
  char hex[100];

  printf("Enter a decimal number: ");
  scanf("%d", &dec);

  // Convert decimal to hexadecimal
  while (dec > 0) {
    rem = dec % 16;
    if (rem < 10) {
      hex[len++] = 48 + rem;
    } else {
      hex[len++] = 55 + rem;
    }
    dec = dec / 16;
  }
  hex[len] = '\0';

  // Print the hexadecimal value of the decimal number
  printf("Hexadecimal value = ");
  for (i = len - 1; i >= 0; i--) {
    printf("%c", hex[i]);
  }
  printf("\n");

  char hex_num[100];
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex_num);

  // Convert hexadecimal to decimal
  int result = 0;
  for (i = 0; hex_num[i] != '\0'; i++) {
    if ('0' <= hex_num[i] && hex_num[i] <= '9') {
      result = result * 16 + (hex_num[i] - '0');
    } else {
      result = result * 16 + (hex_num[i] - 'A' + 10);
    }
  }

  // Print the decimal value of the hexadecimal number
  printf("Decimal value = %d\n", result);

  return 0;
}