//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>
#include <ctype.h>

int main() {
  char hex_value[100], ch;
  int i, decimal_value = 0, j = 0;
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex_value); // Get the hexadecimal input from the user
  for (i = 0; hex_value[i] != '\0'; i++) {
    ch = hex_value[i];
    if (ch >= '0' && ch <= '9') {
      decimal_value = decimal_value * 16 + (ch - '0');
    } else if (ch >= 'A' && ch <= 'F') {
      decimal_value = decimal_value * 16 + (10 + ch - 'A');
    } else if (ch >= 'a' && ch <= 'f') {
      decimal_value = decimal_value * 16 + (10 + ch - 'a');
    } else {
      printf("Invalid Input\n");
      return 0;
    }
  }
  printf("Decimal Equivalent is: %d\n", decimal_value); // Display the decimal equivalent of the input
  return 0;
}