//FormAI DATASET v1.0 Category: Color Code Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  int red, green, blue;

  printf("Welcome to the Color Code Converter!\n");
  printf("Enter the color code in the following RGB format (Separated by commas): R,G,B\n");
  printf("Example: 255,255,255 for pure white.\n");
  
  scanf("%d,%d,%d", &red, &green, &blue);
  
  if(red < 0 || green < 0 || blue < 0 || red > 255 || green > 255 || blue > 255) {
    printf("Invalid input! RGB color code must be between 0 and 255!\n");
  } else {
    int hex = (red << 16) + (green << 8) + blue;

    printf("\n\nConversion results:\n\n");
    printf("RGB color code: %d,%d,%d\n", red, green, blue);
    printf("Hexadecimal color code: #%06X\n", hex);
  }

  printf("\nThanks for using the Color Code Converter! Have a great day!\n");

  return 0;
}