//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>

int main() {
  printf("Welcome to the Color Code Converter program!\n");

  // Read in RGB values
  int r, g, b;
  printf("Enter the red RGB value (0-255): ");
  scanf("%d", &r);
  printf("Enter the green RGB value (0-255): ");
  scanf("%d", &g);
  printf("Enter the blue RGB value (0-255): ");
  scanf("%d", &b);

  // Convert to HEX
  int hex_r = r / 16;
  int hex_r_mod = r % 16;
  int hex_g = g / 16;
  int hex_g_mod = g % 16;
  int hex_b = b / 16;
  int hex_b_mod = b % 16;

  printf("\n");
  printf("Your RGB values: (%d, %d, %d)\n", r, g, b);
  printf("Your HEX values: #%X%X%X%X%X%X\n", hex_r, hex_r_mod, hex_g, hex_g_mod, hex_b, hex_b_mod);

  printf("\nThanks for using the Color Code Converter program!\n");

  return 0;
}