//FormAI DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>

int main() {
  int color; // variable to hold the input color
  printf("Enter a color code in hexadecimal: ");
  scanf("%x", &color); // read the input color in hexadecimal format

  // extract the red, green, and blue components of the color
  int red = (color >> 16) & 0xff;
  int green = (color >> 8) & 0xff;
  int blue = color & 0xff;

  // print the color components in decimal format
  printf("Red: %d\n", red);
  printf("Green: %d\n", green);
  printf("Blue: %d\n", blue);

  // convert the color to grayscale
  int grayscale = (red + green + blue) / 3;

  // print the grayscale color in decimal format
  printf("Grayscale: %d\n", grayscale);

  // convert the color to black and white
  int threshold = 128; // threshold value for black and white conversion
  int bw = (grayscale < threshold) ? 0 : 255; // ternary operator for black and white conversion
  
  // print the black and white color in decimal format
  printf("Black and white: %d\n", bw);

  return 0;
}