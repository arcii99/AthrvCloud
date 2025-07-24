//FormAI DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>

int main() {
  int red, green, blue;
  
  printf("Enter the red value (0-255): ");
  scanf("%d", &red);
  
  if (red < 0 || red > 255) {
    printf("Invalid red value entered.\n");
    return 1; // indicating an error
  }
  
  printf("Enter the green value (0-255): ");
  scanf("%d", &green);
  
  if (green < 0 || green > 255) {
    printf("Invalid green value entered.\n");
    return 1;
  }
  
  printf("Enter the blue value (0-255): ");
  scanf("%d", &blue);
  
  if (blue < 0 || blue > 255) {
    printf("Invalid blue value entered.\n");
    return 1;
  }
  
  // converting RGB values to HEX code
  int hex = ((red & 0xff) << 16) | ((green & 0xff) << 8) | (blue & 0xff);
  
  // printing the HEX code with leading '#' symbol
  printf("\nYour RGB color code is #%06x\n", hex);
  
  return 0;
}