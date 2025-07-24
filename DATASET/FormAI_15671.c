//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int hex, red, green, blue;
  char hexString[7];

  printf("Enter a hexadecimal color code (ex: #FF00FF): ");
  scanf("%s", hexString);

  // Convert hex string to integer
  hex = (int) strtol(&hexString[1], NULL, 16);

  // Extract red, green, and blue values from hex
  red = (hex >> 16) & 0xFF;
  green = (hex >> 8) & 0xFF;
  blue = hex & 0xFF;

  printf("RGB values for %s:\n", hexString);
  printf("Red: %d\n", red);
  printf("Green: %d\n", green);
  printf("Blue: %d\n", blue);

  return 0;
}