//FormAI DATASET v1.0 Category: Color Code Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Color Code Converter! Let's brighten up your day!\n\n");

  char hexValue[7];
  char rgbValue[11];
  char cmykValue[15];

  // Get user input
  printf("Please enter a color code in hex format (e.g. #FF00FF): ");
  scanf("%s", hexValue);

  // Convert hex to RGB
  int r, g, b;
  sscanf(hexValue, "#%2x%2x%2x", &r, &g, &b);
  sprintf(rgbValue, "RGB: (%d,%d,%d)", r, g, b);

  // Convert RGB to CMYK
  float c, m, y, k, red, green, blue;
  red = r / 255.0;
  green = g / 255.0;
  blue = b / 255.0;
  k = 1 - fmax(fmax(red, green), blue);
  if (k == 1) {
    c = 0;
    m = 0;
    y = 0;
  } else {
    c = (1 - red - k) / (1 - k);
    m = (1 - green - k) / (1 - k);
    y = (1 - blue - k) / (1 - k);
  }
  sprintf(cmykValue, "CMYK: (%.2f,%.2f,%.2f,%.2f)", c, m, y, k);

  // Print results
  printf("\n%s\n%s\n", rgbValue, cmykValue);

  return 0;
}