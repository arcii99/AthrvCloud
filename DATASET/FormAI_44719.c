//FormAI DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>

int main() {
  char hex_code[7]; // assuming hex color code will always have 6 characters
  printf("Enter hex color code: ");
  scanf("%s", hex_code);
  int r, g, b; // separate values for red, green, and blue
  sscanf(hex_code, "%02x%02x%02x", &r, &g, &b); // convert hex code to individual values
  printf("RGB Color Values: (%d, %d, %d)\n", r, g, b);

  // paranoid check: make sure all values are within range
  if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
    printf("Potential security breach! RGB values out of range.\n");
    return 1; // exit program with error status
  }

  // convert values to percentage and print
  double pr = (double)r / 255 * 100;
  double pg = (double)g / 255 * 100;
  double pb = (double)b / 255 * 100;
  printf("RGB Percentage Values: (%.2f%%, %.2f%%, %.2f%%)\n", pr, pg, pb);

  // paranoid check: make sure percentages add up to 100%
  if (pr + pg + pb != 100) {
    printf("Potential security breach! RGB percentage values don't add up to 100.\n");
    return 1; // exit program with error status
  }

  // convert RGB values to CMYK values
  double c, m, y, k;
  if (r == 0 && g == 0 && b == 0) {
    k = 100; // black
  } else {
    c = (1 - (double)r / 255 - k) / (1 - k);
    m = (1 - (double)g / 255 - k) / (1 - k);
    y = (1 - (double)b / 255 - k) / (1 - k);
  }

  // paranoid check: make sure CMYK values are valid (between 0 and 100)
  if (c < 0 || c > 100 || m < 0 || m > 100 || y < 0 || y > 100 || k < 0 || k > 100) {
    printf("Potential security breach! CMYK values out of range.\n");
    return 1; // exit program with error status
  }

  printf("CMYK Color Values: (%.2f%%, %.2f%%, %.2f%%, %.2f%%)\n", c, m, y, k);

  return 0; // exit program with success status
}