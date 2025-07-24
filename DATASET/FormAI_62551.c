//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void convertRGBtoHEX(int r, int g, int b);

int main() {
  int r, g, b;

  printf("Enter the RGB values:\n");
  printf("Red: ");
  scanf("%d", &r);
  printf("Green: ");
  scanf("%d", &g);
  printf("Blue: ");
  scanf("%d", &b);

  convertRGBtoHEX(r, g, b);

  return 0;
}

void convertRGBtoHEX(int r, int g, int b) {
  char hex[7];
  sprintf(hex, "#%02x%02x%02x", r, g, b);
  printf("Hexadecimal color code: %s\n", hex);
}