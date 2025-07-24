//FormAI DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int red, green, blue;
  double cyan, magenta, yellow, key;

  printf("Enter red, green, and blue values (0 - 255): ");
  scanf("%d %d %d", &red, &green, &blue);

  // Convert RGB to CMYK
  if (red == 0 && green == 0 && blue == 0) {
    cyan = 0;
    magenta = 0;
    yellow = 0;
    key = 1;
  } else {
    cyan = 1 - (double)red / 255;
    magenta = 1 - (double)green / 255;
    yellow = 1 - (double)blue / 255;
    key = cyan < magenta ? cyan : magenta;
    key = key < yellow ? key : yellow;
    cyan = (cyan - key) / (1 - key);
    magenta = (magenta - key) / (1 - key);
    yellow = (yellow - key) / (1 - key);
  }

  // Convert CMYK to hex code
  int c = (int)(cyan * 255);
  int m = (int)(magenta * 255);
  int y = (int)(yellow * 255);
  int k = (int)(key * 255);
  char colorCode[7];
  sprintf(colorCode, "%02x%02x%02x%02x", c, m, y, k);

  // Output hex code
  printf("The color code is #%s\n", colorCode);

  return 0;
}