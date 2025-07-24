//FormAI DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>

// Convert a color code in hexadecimal to RGB values
void convertToRGB(char colorCode[], int* r, int* g, int* b) {
  sscanf(colorCode, "%2x%2x%2x", r, g, b);
}

// Convert RGB values to a color code in hexadecimal
void convertToHex(int r, int g, int b, char colorCode[]) {
  sprintf(colorCode, "#%02x%02x%02x", r, g, b);
}

int main() {
  // Sample color code in hexadecimal
  char colorCode[] = "#ff5733";

  // Convert the color code to RGB values
  int r, g, b;
  convertToRGB(colorCode, &r, &g, &b);

  // Print the RGB values
  printf("r = %d\n", r);
  printf("g = %d\n", g);
  printf("b = %d\n", b);

  // Modify the RGB values
  r += 50;
  g -= 10;
  b *= 2;

  // Convert the modified RGB values to a color code
  char modifiedColorCode[7];
  convertToHex(r, g, b, modifiedColorCode);

  // Print the modified color code
  printf("Modified color code: %s", modifiedColorCode);

  return 0;
}