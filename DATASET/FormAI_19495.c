//FormAI DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the C Color Code Converter!\nEnter the hexadecimal value of your color code:");

  // Creating variables to store input and output values
  char hex_input[7];
  int r, g, b;

  // Reading the input value
  scanf("%s", hex_input);

  // Converting the hex code to RGB values
  sscanf(hex_input, "%02x%02x%02x", &r, &g, &b);

  // Displaying the RGB values
  printf("The RGB values of the color code %s are:\nR=%d\nG=%d\nB=%d", hex_input, r, g, b);

  // Code conversion options
  printf("\n\nWould you like to convert the RGB values to another color code format? Choose from the options below:");

  printf("\n1: Convert to HEX");
  printf("\n2: Convert to RGB Percentage");
  printf("\n3: Convert to HSL");

  // Reading the conversion option
  int conversion_option;
  scanf("%d", &conversion_option);

  // Displaying the converted value
  switch (conversion_option) {
    case 1:
      printf("The HEX code for the RGB values (%d,%d,%d) is #%02X%02X%02X", r, g, b, r, g, b);
      break;
    case 2:
      printf("The RGB percentage values for (%d,%d,%d) are (%d%%,%d%%,%d%%)", r, g, b, r * 100 / 255, g * 100 / 255, b * 100 / 255);
      break;
    case 3:
      printf("The HSL values for (%d,%d,%d) are (TODO,TODO,TODO)", r, g, b);
      break;
    default:
      printf("Invalid conversion option selected");
  }

  return 0;
}