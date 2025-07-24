//FormAI DATASET v1.0 Category: Color Code Converter ; Style: random
#include<stdio.h>

int main() {
  char hex[6];
  
  printf("Enter a hex code (without the #): ");
  scanf("%s", hex);
  
  // Convert hex code to RGB values
  int r = (int)strtol(hex, NULL, 16) >> 16;
  int g = (int)strtol(hex, NULL, 16) >> 8 & 0xFF;
  int b = (int)strtol(hex, NULL, 16) & 0xFF;
  
  // Output RGB values
  printf("RGB values: %d,%d,%d\n", r, g, b);
  
  // Convert RGB values to CMYK values
  double c = 1 - r / 255.0;
  double m = 1 - g / 255.0;
  double y = 1 - b / 255.0;
  double k = fmin(c, fmin(m, y));
  c = (c - k) / (1 - k);
  m = (m - k) / (1 - k);
  y = (y - k) / (1 - k);
  
  // Output CMYK values
  printf("CMYK values: %.2f,%.2f,%.2f,%.2f", c, m, y, k);
  
  return 0;
}