//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>

int main() {
  char color_code[7], hex[7], rgb[3];
  int i;

  printf("Enter a color code: ");
  scanf("%s", color_code);

  // Convert color code from hex to RGB
  for (i = 1; i <= 3; i++) {
    sscanf(color_code + i*2, "%2hhx", &rgb[i-1]);
  }

  // Convert RGB to hex
  sprintf(hex, "%02x%02x%02x", rgb[0], rgb[1], rgb[2]);

  printf("Hex value: #%s\n", hex);
  printf("RGB value: (%d, %d, %d)\n", rgb[0], rgb[1], rgb[2]);

  return 0;
}