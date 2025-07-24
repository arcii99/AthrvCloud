//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void colorCodeConverter(int r, int g, int b) {
  int hexValue = (r << 16) + (g << 8) + b;

  printf("The RGB color code (%d, %d, %d) converts to hex code #%06X\n", r, g, b, hexValue);
}

int main() {

  int rValue, gValue, bValue;

  printf("Welcome to Sherlock Holmes' color code converter!\n");
  printf("Please enter the red value (0-255): ");
  scanf("%d", &rValue);

  printf("Please enter the green value (0-255): ");
  scanf("%d", &gValue);

  printf("Please enter the blue value (0-255): ");
  scanf("%d", &bValue);

  if ((rValue >= 0 && rValue <= 255) && (gValue >= 0 && gValue <= 255) && (bValue >= 0 && bValue <= 255)) {
    colorCodeConverter(rValue, gValue, bValue);
  } else {
    printf("Invalid input. Please enter values between 0-255.\n");
  }

  return 0;
}