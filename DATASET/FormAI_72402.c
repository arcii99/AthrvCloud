//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  char code[7];
  printf("Enter the color code to be converted: ");
  scanf("%s", code);

  // converting the color code to RGB values
  int r = (int) (code[1] - '0') * 16 + (code[2] - '0');
  int g = (int) (code[3] - '0') * 16 + (code[4] - '0');
  int b = (int) (code[5] - '0') * 16 + (code[6] - '0');

  // printing the RGB values
  printf("The RGB value for the color code %s is (%d, %d, %d).\n", code, r, g, b);

  return 0;
}