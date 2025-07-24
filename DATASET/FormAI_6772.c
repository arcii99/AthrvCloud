//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>

int main() {
  printf("Welcome to our Color Code Converter!\n");
  
  float r, g, b, c, m, y, k;
  printf("Please enter your RGB values from 0-255:\n");
  scanf("%f %f %f", &r, &g, &b);
  
  c = (255 - r) / 255.0;
  m = (255 - g) / 255.0;
  y = (255 - b) / 255.0;
  
  if (c == 1 && m == 1 && y == 1) {
    k = 1;
  } else {
    k = fmin(c, fmin(m, y));
    c = (c - k) / (1 - k);
    m = (m - k) / (1 - k);
    y = (y - k) / (1 - k);
  }
  
  printf("Your CMYK values are:\n");
  printf("C: %f\n", c);
  printf("M: %f\n", m);
  printf("Y: %f\n", y);
  printf("K: %f\n", k);
  
  printf("Thank you for using our Color Code Converter!");
  return 0;
}