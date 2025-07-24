//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>

int main() {

  // welcome message
  printf("Welcome to our C Color Code Converter.\n\n");
  
  // variables declaration
  char colorCode[7];
  int r, g, b;
  
  // input color code
  printf("Please enter a valid color code (e.g. #FF0000): ");
  scanf("%s", colorCode);
  
  // extract red, green, and blue values
  r = (int)strtol(&colorCode[1], NULL, 16);
  g = (int)strtol(&colorCode[3], NULL, 16);
  b = (int)strtol(&colorCode[5], NULL, 16);
  
  // output RGB values
  printf("\nRGB values for %s are: %d, %d, %d\n\n", colorCode, r, g, b);

  // return success code
  return 0;
}