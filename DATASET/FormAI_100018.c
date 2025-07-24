//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>

int main() {
  char hex[10], character;
  int num, red, green, blue;

  printf("Enter a hex code: ");
  scanf("%s", hex);

  num = (int)strtol(hex, NULL, 16); // converts hex to decimal

  red = (num >> 16) & 0xFF; // bitwise operation to extract red value
  green = (num >> 8) & 0xFF; // bitwise operation to extract green value
  blue = num & 0xFF; // bitwise operation to extract blue value

  printf("\nRGB color: (%d, %d, %d)", red, green, blue);

  printf("\n\nEnter an RGB color (r,g,b): ");
  scanf("%d,%d,%d", &red, &green, &blue);

  printf("\nHex code: #%02x%02x%02x", red, green, blue); 
    // %02x formats hex values with leading zeros if needed
  
  printf("\n\nEnter a character: ");
  fflush(stdin); // flushes stdin buffer to prevent issue with scanf
  
  scanf("%c", &character);

  printf("\nASCII code for %c is %d", character, character);

  return 0;
}