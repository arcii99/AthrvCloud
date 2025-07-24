//FormAI DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>

int main() {
  char input[10];
  printf("Enter the color code (e.g. #FF0000): ");
  scanf("%s", input);

  if (input[0] != '#') {
    printf("Invalid color code format.\n");
    return 1;
  }

  int r, g, b;
  sscanf(input, "#%02x%02x%02x", &r, &g, &b);

  printf("RGB values: (%d, %d, %d)\n", r, g, b);

  // convert to CMYK
  double c = 1 - (double)r / 255;
  double m = 1 - (double)g / 255;
  double y = 1 - (double)b / 255;
  double k = fmin(c, fmin(m, y));
  if (k == 1) {
    c = m = y = 0;
  } else {
    c = (c - k) / (1 - k);
    m = (m - k) / (1 - k);
    y = (y - k) / (1 - k);
  }

  printf("CMYK values: (%.2lf, %.2lf, %.2lf, %.2lf)\n", c, m, y, k);

  return 0;
}