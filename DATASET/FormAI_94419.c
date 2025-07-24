//FormAI DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>

int main() {
  char hexCode[7]; // maximum number of characters for a hex code
  printf("Enter a hexadecimal color code (without the # symbol): ");
  scanf("%s", hexCode); // read user input

  int r, g, b;
  sscanf(hexCode, "%02x%02x%02x", &r, &g, &b); // convert hex code to RGB values

  printf("Red: %d\n", r);
  printf("Green: %d\n", g);
  printf("Blue: %d\n", b);

  // convert RGB color code to CMYK color code
  float c, m, y, k;
  c = 1 - (float)r / 255;
  m = 1 - (float)g / 255;
  y = 1 - (float)b / 255;
  k = fminf(c, fminf(m, y)); // minimum color value calculation

  if (k == 1) { // black
    c = 0;
    m = 0;
    y = 0;
  } else {
    c = (c - k) / (1 - k);
    m = (m - k) / (1 - k);
    y = (y - k) / (1 - k);
  }

  printf("CMYK Color Code: %.2f, %.2f, %.2f, %.2f\n", c, m, y, k);

  return 0;
}