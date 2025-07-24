//FormAI DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>

int main() {
  int color_code;
  printf("Enter a color code value between 0 and 255: ");
  scanf("%d", &color_code);
  
  // calculate red, green, and blue values
  int red = color_code / 65536;
  int green = (color_code % 65536) / 256;
  int blue = color_code % 256;
  
  printf("The RGB values for color code %d are: %d, %d, %d\n", color_code, red, green, blue);
  
  // convert RGB values to CMYK values
  float c, m, y, k;
  c = (255 - red) / 255.0;
  m = (255 - green) / 255.0;
  y = (255 - blue) / 255.0;
  
  if (c < m) {
    k = c;
  } else {
    k = m;
  }
  
  if (y < k) {
    k = y;
  }
  
  c = (c - k) / (1 - k);
  m = (m - k) / (1 - k);
  y = (y - k) / (1 - k);
  
  printf("The CMYK values for color code %d are: %.2f, %.2f, %.2f, %.2f\n", color_code, c, m, y, k);
  
  return 0;
}