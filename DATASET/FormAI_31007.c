//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  char hex[30];
  int decimal = 0, i = 0, j = 0;

  printf("Welcome to the Hexadecimal Converter! Enter the hexadecimal value: ");
  scanf("%s", hex);

  while (hex[i] != '\0') {
    // check for validity of hexadecimal digit
    if (!(hex[i] >= '0' && hex[i] <= '9') && !(hex[i] >= 'A' && hex[i] <= 'F') && !(hex[i] >= 'a' && hex[i] <= 'f')) {
      printf("Invalid hex digit: %c\n", hex[i]);
      return 0;
    }

    // convert higher order digit of 2-digit hex number
    if (hex[i] >= 'A' && hex[i] <= 'F') {
      decimal = decimal * 16 + (hex[i] - 55);
    }

    // convert higher order digit of 2-digit hex number (lowercase)
    else if (hex[i] >= 'a' && hex[i] <= 'f') {
      decimal = decimal * 16 + (hex[i] - 87);
    }

    // convert lower order digit of 2-digit hex number
    else {
      decimal = decimal * 16 + (hex[i] - '0');
      j++;
    }

    i++;
  }

  //print out the decimal number
  printf("The decimal equivalent of hexadecimal %s is: %d.\n", hex, decimal);

  return 0;
}