//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>

int main() {
  char colorCode[7];
  printf("Enter a 6 digit hexadecimal color code (without the # symbol): ");
  scanf("%s", colorCode);
  printf("The RGB color code for #%s is:", colorCode);

  //converting code to RGB (Red Green Blue)
  int r = (int) strtol(colorCode, NULL, 16) >> 16 & 0xFF;
  int g = (int) strtol(colorCode, NULL, 16) >> 8 & 0xFF;
  int b = (int) strtol(colorCode, NULL, 16) & 0xFF;

  printf(" RGB(%d, %d, %d)\n", r, g, b);

  return 0;
}