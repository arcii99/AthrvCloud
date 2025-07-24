//FormAI DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>

int main() {
  int red, green, blue;
  float cyan, magenta, yellow, key;

  printf("Enter C Color Code (e.g. 0.65, 0.30, 0.05, 0.20): ");
  scanf("%f, %f, %f, %f", &cyan, &magenta, &yellow, &key);

  red = (1 - cyan) * (1 - key) * 255;
  green = (1 - magenta) * (1 - key) * 255;
  blue = (1 - yellow) * (1 - key) * 255;

  printf("RGB Color Code: (%d, %d, %d)\n", red, green, blue);

  return 0;
}