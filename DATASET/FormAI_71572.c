//FormAI DATASET v1.0 Category: Color Code Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDecimal(char hexVal[]) {
  int len = strlen(hexVal);
  int base = 1;
  int decimalVal = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (hexVal[i] >= '0' && hexVal[i] <= '9') {
      decimalVal += (hexVal[i] - 48) * base;
      base *= 16;
    } else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
      decimalVal += (hexVal[i] - 55) * base;
      base *= 16;
    }
  }

  return decimalVal;
}

int main() {
  char hexCode[7] = "#FF0000";
  char red[3];
  char green[3];
  char blue[3];

  strncpy(red, hexCode + 1, 2);
  strncpy(green, hexCode + 3, 2);
  strncpy(blue, hexCode + 5, 2);

  red[2] = '\0';
  green[2] = '\0';
  blue[2] = '\0';

  int r = hexToDecimal(red);
  int g = hexToDecimal(green);
  int b = hexToDecimal(blue);

  printf("The RGB color code for %s is (%d, %d, %d)\n", hexCode, r, g, b);

  return 0;
}