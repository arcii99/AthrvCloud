//FormAI DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to convert Hex to RGB
void hex_to_rgb(char hex_code[], int rgb[]) {
  int r, g, b;
  sscanf(hex_code, "#%02x%02x%02x", &r, &g, &b);
  rgb[0] = r;
  rgb[1] = g;
  rgb[2] = b;
}

// Function to convert RGB to Hex
void rgb_to_hex(int r, int g, int b, char hex_code[]) {
  sprintf(hex_code, "#%02x%02x%02x", r, g, b);
}

// Main function
int main() {
  printf("Welcome to the Color Code Converter.\n\n");

  // Ask user for input
  printf("Enter the color code you want to convert: ");
  char input_code[7];
  scanf("%s", input_code);

  // Check if input is valid hex code
  if (strspn(input_code, "0123456789abcdefABCDEF") != 6) {
    printf("\nInvalid input. Please enter a 6 digit hexadecimal code.\n\n");
    return 0;
  }

  // Convert hex code to RGB
  int rgb[3];
  hex_to_rgb(input_code, rgb);

  // Print RGB values
  printf("\nThe RGB values are: %d, %d, %d\n", rgb[0], rgb[1], rgb[2]);

  // Convert RGB values to Hex
  char hex_code[7];
  rgb_to_hex(rgb[0], rgb[1], rgb[2], hex_code);

  // Print Hex code
  printf("\nThe Hex code is: %s\n\n", hex_code);

  return 0;
}