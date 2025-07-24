//FormAI DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>

int main() {
  int r, g, b;
  
  printf("Enter RGB color values (0-255):\n");
  printf("Red: ");
  scanf("%d", &r);
  printf("Green: ");
  scanf("%d", &g);
  printf("Blue: ");
  scanf("%d", &b);

  // Convert RGB to HEX
  int hex = (r << 16) + (g << 8) + b;
  printf("\nThe HEX code is: #%06x\n", hex);

  // Convert HEX to RGB
  int r2 = (hex >> 16) & 0xff;
  int g2 = (hex >> 8) & 0xff;
  int b2 = hex & 0xff;
  printf("\nThe RGB values are: %d, %d, %d\n", r2, g2, b2);

  return 0;
}