//FormAI DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>

int main() {
  printf("Welcome to RGB to HEX converter\n");
  printf("Enter R, G, B values between 0 - 255 separated by space:\n");
  
  int red, green, blue;
  scanf("%d %d %d", &red, &green, &blue);

  if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
    printf("Invalid input. Please enter values between 0 - 255.\n");
    return 1;
  }

  printf("RGB: %d %d %d\n", red, green, blue);

  int hex1 = red / 16;
  int hex2 = red % 16;
  int hex3 = green / 16;
  int hex4 = green % 16;
  int hex5 = blue / 16;
  int hex6 = blue % 16;

  char hexCode[8];
  sprintf(hexCode, "#%X%X%X%X%X%X", hex1, hex2, hex3, hex4, hex5, hex6);

  printf("HEX: %s\n", hexCode);

  return 0;
}