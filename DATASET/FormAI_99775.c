//FormAI DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>

int main() {
  printf("Welcome to the C Color Code Converter!\n");
  
  // Initialize variables for RGB values
  int red, blue, green;

  // Prompt user for input
  printf("Please enter the red value (0 to 255): ");
  scanf("%d", &red);
  printf("Please enter the green value (0 to 255): ");
  scanf("%d", &green);
  printf("Please enter the blue value (0 to 255): ");
  scanf("%d", &blue);
  
  // Check that input is valid
  if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
    printf("Error: RGB values should be between 0 and 255.\n");
    return 1;
  }
  
  // Convert RGB values to hexadecimal
  char hex[7];
  sprintf(hex, "#%02X%02X%02X", red, green, blue);
  
  // Print out hexadecimal code
  printf("The color in hexadecimal is: %s\n", hex);
  
  // Convert hexadecimal code back to RGB values
  sscanf(hex, "#%02X%02X%02X", &red, &green, &blue);
  
  // Print out RGB values
  printf("The color in RGB values is: (%d, %d, %d)\n", red, green, blue);
  
  return 0;
}