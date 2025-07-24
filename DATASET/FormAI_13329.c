//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>

// define a structure to store color codes
struct Color {
  int red;
  int green;
  int blue;
};

// function to convert hex color code to RGB
struct Color hexToRGB(char hex[]) {
  struct Color color;
  sscanf(hex, "#%02x%02x%02x", &color.red, &color.green, &color.blue);
  return color;
}

// function to convert RGB color code to hexadecimal
char* RGBToHex(struct Color color) {
  static char hex[7];
  sprintf(hex, "#%02x%02x%02x", color.red, color.green, color.blue);
  return hex;
}

int main() {
  char hexCode[7];
  struct Color color;
  
  printf("Enter a hexadecimal color code: ");
  scanf("%s", hexCode);
  
  color = hexToRGB(hexCode);
  
  printf("RGB color code: %d, %d, %d\n", color.red, color.green, color.blue);
  
  printf("Enter an RGB color code (separated by commas): ");
  scanf("%d, %d, %d", &color.red, &color.green, &color.blue);
  
  printf("Hexadecimal color code: %s\n", RGBToHex(color));
  
  return 0;
}