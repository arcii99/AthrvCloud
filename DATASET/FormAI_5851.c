//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertColorCode(char hexCode[]);

int main() {
  char hexCode[7];
  printf("Enter a hex color code: ");
  scanf("%s", hexCode);

  printf("\nYour hex code is %s \n\n", hexCode);
  printf("Let me convert it to RGB color code...\n\n");

  convertColorCode(hexCode);

  printf("\nAwesome! The RGB color code is now ready.\n");
  return 0;
}

void convertColorCode(char hexCode[]) {
  int r, g, b;
  char rCode[3], gCode[3], bCode[3];

  strncpy(rCode, hexCode+0, 2);
  strncpy(gCode, hexCode+2, 2);
  strncpy(bCode, hexCode+4, 2);

  r = strtol(rCode, NULL, 16);
  g = strtol(gCode, NULL, 16);
  b = strtol(bCode, NULL, 16);

  printf("RGB code: %d,%d,%d", r, g, b);
}