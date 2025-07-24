//FormAI DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  char hex[7];

  // Ask the user for a hex color code
  printf("Enter a hex color code (e.g. #FF5733): ");
  scanf("%s", hex);

  // Convert hex to RGB
  int r = strtol(&hex[1], NULL, 16) >> 16;
  int g = strtol(&hex[3], NULL, 16) >> 8;
  int b = strtol(&hex[5], NULL, 16);

  // Print the RGB values
  printf("Red: %d\n", r);
  printf("Green: %d\n", g);
  printf("Blue: %d\n", b);

  // Convert RGB to hex
  sprintf(hex, "#%02X%02X%02X", r, g, b);

  // Print the hex color code
  printf("Hex color code: %s\n", hex);

  return 0;
}