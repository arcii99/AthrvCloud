//FormAI DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
  int red, green, blue;

  printf("Please enter the hexadecimal color code (e.g. #FF0000): ");
  char color[7];
  scanf("%s", color);

  // Convert hex color code to decimal RGB values
  sscanf(color, "#%02x%02x%02x", &red, &green, &blue);

  printf("\nThe RGB values for %s are: %d, %d, %d", color, red, green, blue);

  // Convert decimal RGB values to CMYK values
  double c, m, y, k;
  c = 1 - (double) red / 255;
  m = 1 - (double) green / 255;
  y = 1 - (double) blue / 255;
  double minCMY = fmin(fmin(c, m), y);
  c = (c - minCMY) / (1 - minCMY);
  m = (m - minCMY) / (1 - minCMY);
  y = (y - minCMY) / (1 - minCMY);
  k = minCMY;

  printf("\nThe CMYK values for %s are: %.2f, %.2f, %.2f, %.2f", color, c, m, y, k);

  return 0;
}