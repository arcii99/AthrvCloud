//FormAI DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>

int main() {
  int colorCode;

  printf("Enter a color code (integer between 0 and 16777215): ");
  scanf("%d", &colorCode);
  
  printf("The RGB values of color code %d are: \n", colorCode);
  
  int red = (colorCode >> 16) & 0xFF;
  int green = (colorCode >> 8) & 0xFF;
  int blue = colorCode & 0xFF;
  
  printf("Red: %d\n", red);
  printf("Green: %d\n", green);
  printf("Blue: %d\n", blue);
  
  return 0;
}