//FormAI DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>

int main() {
  int red, green, blue;
  printf("Enter the red value (0-255): ");
  scanf("%d", &red);

  printf("Enter the green value (0-255): ");
  scanf("%d", &green);

  printf("Enter the blue value (0-255): ");
  scanf("%d", &blue);

  // Convert RGB to HEX
  int hex1 = red / 16;
  int hex2 = red % 16;
  int hex3 = green / 16;
  int hex4 = green % 16;
  int hex5 = blue / 16;
  int hex6 = blue % 16;

  // Convert HEX to C color code format
  char hex[8];
  sprintf(hex, "#%X%X%X%X%X%X", hex1, hex2, hex3, hex4, hex5, hex6);

  // Print the result
  printf("The C color code for RGB (%d, %d, %d) is %s\n", red, green, blue, hex);

  return 0;
}