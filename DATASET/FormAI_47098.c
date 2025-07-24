//FormAI DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  char colorCode[7]; // 6 characters for the actual code + 1 for the terminating null character
  printf("Welcome to the Color Code Converter!\n");
  printf("Enter a valid hexadecimal color code: ");
  scanf("%s", colorCode);
  for (int i = 0; i < 6; i++) {
    if (colorCode[i] >= 'a' && colorCode[i] <= 'z') {
      colorCode[i] = colorCode[i] - 32; // convert lowercase letters to uppercase
    }
  }
  printf("Your entered color code is #%s\n", colorCode);
  printf("Converting...\n");
  unsigned long int decimal = strtoul(colorCode, NULL, 16); // convert hexadecimal string to decimal number
  printf("Decimal representation: %lu\n", decimal);
  int red = (decimal >> 16) & 0xff; // extract red value (bits 16-23)
  int green = (decimal >> 8) & 0xff; // extract green value (bits 8-15)
  int blue = decimal & 0xff; // extract blue value (bits 0-7)
  printf("RGB representation: (%d, %d, %d)\n", red, green, blue);
  printf("Thanks for using the Color Code Converter! Goodbye.\n");
  return 0;
}